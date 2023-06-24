#include "main.h"

/**
 * rotl_ist - instruction to rotate the linked list circularly left
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void rotl_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number) {}
/**
 * rotr_ist - instruction to rotate the linked list circularly right
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void rotr_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number) {}
/**
 * stack_ist - instruction to change to stack operation mode
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void stack_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
{
	global_wrapper.SQ_flag = STACK_F;
}
/**
 * queue_ist - instruction to change to queue operation mode
 *
 * @stack: the address of the pointer to the input stack variable
 * @line_number: the number of the current execution line
 */
void queue_ist(__attribute__((__unused__))stack_t **stack,
	__attribute__((__unused__))unsigned int line_number)
{
	global_wrapper.SQ_flag = QUEUE_F;
}
