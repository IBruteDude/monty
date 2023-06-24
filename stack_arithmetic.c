#include "monty.h"

/**
 * add_ist - instruction to perform add operation on the last two elements
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void add_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
{
	stack_t *s1, *s2;

	s1 = pop_new(&global_wrapper);
	s2 = pop_new(&global_wrapper);
	if (s1 == NULL || s2 == NULL)
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	push_new(&global_wrapper, s2->n + s1->n);
}
/**
 * sub_ist - instruction to perform subtract operation on the last two elements
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void sub_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
{
	stack_t *s1, *s2;

	s1 = pop_new(&global_wrapper);
	s2 = pop_new(&global_wrapper);
	if (s1 == NULL || s2 == NULL)
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	push_new(&global_wrapper, s2->n - s1->n);
}
/**
 * mul_ist - instruction to perform multiply operation on the last two elements
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void mul_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
{
	stack_t *s1, *s2;

	s1 = pop_new(&global_wrapper);
	s2 = pop_new(&global_wrapper);
	if (s1 == NULL || s2 == NULL)
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number),
		exit(EXIT_FAILURE);
	push_new(&global_wrapper, s2->n * s1->n);
}
/**
 * div_ist - instruction to perform division operation on the last two elements
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void div_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
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
/**
 * mod_ist - instruction to perform modulo operation on the last two elements
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void mod_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
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
