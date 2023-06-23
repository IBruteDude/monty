#include "main.h"

void pall_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	stack_t *stack_node = NULL;

	do {
		stack_node = iterator(&global_wrapper, stack_node);
		if (stack_node != NULL)
			printf("%d\n", stack_node->n);
	} while (stack_node != NULL);
}
void pint_ist(stack_t **stack UU_VAR, unsigned int line_number)
{
	stack_t *stack_node = NULL;

	stack_node = iterator(&global_wrapper, stack_node);
	if (stack_node != NULL)
		printf("%d\n", stack_node->n);
	else
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number),
		exit(EXIT_FAILURE);
}
void pchar_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	stack_t *stack_node = NULL;

	stack_node = iterator(&global_wrapper, stack_node);
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
void pstr_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	stack_t *stack_node = NULL;

	do {
		stack_node = iterator(&global_wrapper, stack_node);
		if (stack_node != NULL && stack_node->n > 0 && stack_node->n <= 127)
			putchar(stack_node->n);
	} while (stack_node != NULL && stack_node->n > 0 && stack_node->n <= 127);
	putchar('\n');
}
