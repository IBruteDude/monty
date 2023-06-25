#include "monty.h"

SQW global_wrapper;

/**
 * tokenise - split a whitespace interspersed line into tokens
 *
 * @line: input line
 * Return: tokens array
 */
char **tokenise(char *line)
{
	int tk_l = 0;
	char *tk, **tks = malloc(2 * sizeof(char *));

	MALLOC_CHECK(tks);
	tks[1] = NULL;
	while (isspace(*line))
		line++;
	if (*line != '\0')
	{
		while (!isspace(line[tk_l]) && line[tk_l] != '\0' && line[tk_l] != '#')
			tk_l++;
		tk = malloc(tk_l + 1), tk[tk_l] = '\0';
		MALLOC_CHECK(tk);
		if (line[tk_l] == '\0')
		{
			strcpy(tk, line);
			tks[0] = tk;
		}
		else
		{
			line[tk_l] = '\0';
			strcpy(tk, line), line += tk_l + 1, tk_l = 0;
			tks[0] = tk;
			while (isspace(*line) && *line != '-' && *line != '+')
				line++;
			while (isintlit(line[tk_l]))
				tk_l++;
			if (tk_l != 0)
			{
				tk = malloc(tk_l + 1);
				MALLOC_CHECK(tk);
				tk[tk_l] = '\0', strncpy(tk, line, tk_l);
				tks[1] = tk;
			}
		}
	}
	else
	{
		tks[0] = malloc(1);
		tks[0][0] = '\0'; 
	}
	return (tks);
}

/**
 * exec_instruction - execute an instruction
 *
 * @tok_arr: the parsed tokens array
 * @line_no: the execution line number
 * Return: exit status
 */
int exec_instruction(char **tok_arr, unsigned int line_no)
{
	int i = 1;
	stack_t *stack_node;

	instruction_t insts[] = {
		{"push", push_ist}, {"pop", pop_ist}, {"nop", nop_ist},
		{"rotl", rotl_ist}, {"rotr", rotr_ist}, {"swap", swap_ist},
		{"pall", pall_ist}, {"pint", pint_ist}, {"pchar", pchar_ist},
		{"pstr", pstr_ist}, {"stack", stack_ist}, {"queue", queue_ist},
		{"add", add_ist}, {"sub", sub_ist}, {"div", div_ist},
		{"mul", mul_ist}, {"mod", mod_ist},
		{NULL, NULL}
	};
	if (strcmp(tok_arr[0], "push") == 0)
	{
		if (tok_arr[1] == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			return (EXIT_FAILURE);
		}
		push_new(atoi(tok_arr[1]));
		return (EXIT_SUCCESS);
	}
	for (i = 1; insts[i].opcode != NULL; i++)
		if (strcmp(insts[i].opcode, tok_arr[0]) == 0)
		{
			stack_node = iterator(NULL);
			insts[i].f(&stack_node, line_no);
			return (EXIT_SUCCESS);
		}
	if (strcmp(tok_arr[0], ""))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, tok_arr[0]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * _getline - a stupid implementation because I can't get the original to work
 *
 * @lineptr: the address of the line write buffer
 * @n: the address storing the length of the buffer
 * @stream: the input file stream
 * Return: number of read bytes or EOF if it's hit
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int i = 0, buf_siz = *n/* 1024 */;
	char read_char, *temp, *line = *lineptr/* malloc(buf_siz) */;

	MALLOC_CHECK(line);
	do {
		read_char = getc(stream);
		if (feof(stream))
			break;
		if (i >= 1023)
		{
			temp = malloc(buf_siz += 1024);
			strncpy(temp, line, 1023);
			free(line);
		}
		line[i] = read_char;
		i++;
	} while (read_char != '\n' && read_char != '\0');
	line[i] = '\0';
	/* if (*lineptr) */
		/* free(*lineptr); */
	*n = (size_t)buf_siz;
	*lineptr = line;
	if (feof(stream))
		return (EOF);
	return (i);
}

/**
 * main - the monty interpreter's main
 *
 * @argc: argument count
 * @argv: arguments array
 * Return: exit status
 */
int main(int argc, char *argv[])
{
	unsigned int i, line_no = 1, exec_stat = EXIT_SUCCESS;
	size_t line_len = 1024;
	FILE *infile;
	char **tk_arr, *line = malloc(line_len);

	if (argc < 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	MALLOC_CHECK(line);
	global_wrapper.SQ_flag = STACK_F;
	global_wrapper.head = global_wrapper.tail = NULL;
	for (i = 1; i < (unsigned int)argc && exec_stat == EXIT_SUCCESS; i++)
	{
		infile = fopen(argv[i], "r");
		if (infile == NULL)
			fprintf(stderr, "Error: Can't open file %s\n", argv[i]),
			free(line), exit(EXIT_FAILURE);
		do {
			_getline(&line, &line_len, infile);
			tk_arr = tokenise(line);
			exec_stat = exec_instruction(tk_arr, line_no);
			free(tk_arr[0]), free(tk_arr[1]), free(tk_arr);
			line_no++;
		} while (!feof(infile) && exec_stat == EXIT_SUCCESS);
		free_SQW();
		fclose(infile);
	}
	free(line);
	return (exec_stat);
}
