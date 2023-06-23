#include "main.h"

void add_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	stack_t *s1, *s2;

	s1 = pop_new(&global_wrapper);
	s2 = pop_new(&global_wrapper);
	if (s1 == NULL || s2 == NULL)
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	push_new(&global_wrapper, s2->n + s1->n);
}
void sub_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	stack_t *s1, *s2;

	s1 = pop_new(&global_wrapper);
	s2 = pop_new(&global_wrapper);
	if (s1 == NULL || s2 == NULL)
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	push_new(&global_wrapper, s2->n - s1->n);
}
void mul_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	stack_t *s1, *s2;

	s1 = pop_new(&global_wrapper);
	s2 = pop_new(&global_wrapper);
	if (s1 == NULL || s2 == NULL)
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	push_new(&global_wrapper, s2->n * s1->n);
}
void div_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	stack_t *s1, *s2;

	s1 = pop_new(&global_wrapper);
	s2 = pop_new(&global_wrapper);
	if (s1 == NULL || s2 == NULL)
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	if (s1->n == 0)
		fprintf(stderr, "L%d: division by zero\n", line_number),
		exit(EXIT_FAILURE);
	push_new(&global_wrapper, s2->n / s1->n);
}
void mod_ist(stack_t **stack UU_VAR, unsigned int line_number UU_VAR)
{
	stack_t *s1, *s2;

	s1 = pop_new(&global_wrapper);
	s2 = pop_new(&global_wrapper);
	if (s1 == NULL || s2 == NULL)
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	if (s1->n == 0)
		fprintf(stderr, "L%d: division by zero\n", line_number),
		exit(EXIT_FAILURE);
	push_new(&global_wrapper, s2->n % s1->n);
}
