#include "main.h"

typedef instruction_t ist;

instruction_t insts[] = {
	{"push", push_ist},
	{"pall", pall_ist},
	{"pint", pint_ist},
	{"pop", pop_ist},
	{"swap", swap_ist},
	{"add", add_ist},
	{"nop", nop_ist},
	{"sub", sub_ist},
	{"div", div_ist},
	{"mul", mul_ist},
	{"mod", mod_ist},
	{"pchar", pchar_ist},
	{"pstr", pstr_ist},
	{"rotl", rotl_ist},
	{"rotr", rotr_ist},
	{"stack", stack_ist},
	{"queue", queue_ist},
	{NULL, NULL}
};
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
	tks[0] = malloc(1), tks[0][0] = '\0', tks[1] = NULL;
	while (isspace(*line))
		line++;
	if (*line != '\0')
	{
		while (!isspace(line[tk_l]) && line[tk_l] != '\0')
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
			while (isspace(*line))
				line++;
			while (isdigit(line[tk_l]))
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
	return tks;
}


void exec_ist(char **tok_arr, unsigned int line_no)
{
	int i = 1;
	stack_t *stack_node;

	if (strcmp(tok_arr[0], "push") == 0)
	{
		if (tok_arr[1] == NULL)
			fprintf(stderr, "L%d: usage: push integer\n", line_no), exit(EXIT_FAILURE);
		push_new(&global_wrapper, atoi(tok_arr[1]));
		return ;
	}
	while (insts[i].opcode != NULL)
	{
		if (strcmp(insts[i].opcode, tok_arr[0]) == 0)
		{
			stack_node = iterator(&global_wrapper, NULL);
			insts[i].f(&stack_node, line_no);
			return ;
		}
		i++;
	}
}

typedef signed long int ssize_t;

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	int i = 0, buf_siz = 1024;
	char read_char, *temp, *line = malloc(buf_siz);

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
	if (*lineptr)
		free(*lineptr);
	*n = (size_t) i;
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
	unsigned int i, line_no = 1;
	size_t line_len = 1;
	FILE *infile;
	char **tk_arr, *line = malloc(1);
	SQW global_wrapper;

	if (argc < 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	MALLOC_CHECK(line);
	global_wrapper.SQ_flag = STACK_F;
	global_wrapper.head = global_wrapper.tail = NULL;
	for (i = 1; i < (unsigned int)argc; i++)
	{
		infile = fopen(argv[i], "r");
		if (infile == NULL)
			fprintf(stderr, "Error: Can't open file %s\n", argv[i]), exit(EXIT_FAILURE);
		while (getline(&line, &line_len, infile) != EOF)
		{
			tk_arr = tokenise(line);
			/* printf("L%d = %s : %s", line_no, tk_arr[0], tk_arr[1]); */
			exec_ist(tk_arr, line_no);
			line_no++;
		}
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}