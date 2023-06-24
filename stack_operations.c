#include "main.h"

/**
 * push_ist - empty instruction for pushing a new element
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void push_ist(__attribute__((__unused__)) stack_t **stack,
	__attribute__((__unused__)) unsigned int line_number) {}
/**
 * pop_ist - instruction to check for popping an element off the linked list
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void pop_ist(__attribute__((__unused__)) stack_t **stack,
	__attribute__((__unused__)) unsigned int line_number)
{
	if (pop_new(&global_wrapper) == NULL)
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number),
		exit(EXIT_FAILURE);
}
/**
 * swap_ist - instruction to swap the last two linked list elements
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void swap_ist(__attribute__((__unused__)) stack_t **stack,
	__attribute__((__unused__)) unsigned int line_number)
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
/**
 * nop_ist - the null/no operation instruction
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void nop_ist(__attribute__((__unused__)) stack_t **stack,
	__attribute__((__unused__)) unsigned int line_number) {}
