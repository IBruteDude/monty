#include "main.h"

void push_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR) {}
void pop_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	if (pop_new(&global_wrapper) == NULL)
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number),
		exit(EXIT_FAILURE);
}
void swap_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	stack_t *s1, *s2;

	s1 = pop_new(&global_wrapper);
	s2 = pop_new(&global_wrapper);
	if (s1 == NULL || s2 == NULL)
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	push_new(&global_wrapper, s1->n);
	push_new(&global_wrapper, s2->n);
}
void nop_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR) {}
