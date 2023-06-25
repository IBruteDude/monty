#include "monty.h"

/**
 * pall_ist - instruction to print the whole linked list
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void pall_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
{
	stack_t *stack_node = NULL;

	do {
		stack_node = iterator(stack_node);
		if (stack_node != NULL)
			printf("%d\n", stack_node->n);
	} while (stack_node != NULL);
}
/**
 * pint_ist - instruction to print last pushed integer
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void pint_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
{
	stack_t *stack_node = NULL;

	stack_node = iterator(stack_node);
	if (stack_node != NULL)
		printf("%d\n", stack_node->n);
	else
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number),
		exit(EXIT_FAILURE);
}
/**
 * pchar_ist - instruction to print the last pushed integer as a char
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void pchar_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
{
	stack_t *stack_node = NULL;

	stack_node = iterator(stack_node);
	if (stack_node != NULL)
	{
		if (stack_node->n <= 127 && stack_node->n >= 0)
			printf("%c\n", stack_node->n);
		else
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number),
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number),
		exit(EXIT_FAILURE);
}
/**
 * pstr_ist - instruction to print a valid string of stack stored chars
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void pstr_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
{
	stack_t *stack_node = NULL;

	do {
		stack_node = iterator(stack_node);
		if (stack_node != NULL && stack_node->n > 0 && stack_node->n <= 127)
			putchar(stack_node->n);
	} while (stack_node != NULL && stack_node->n > 0 && stack_node->n <= 127);
	putchar('\n');
}
