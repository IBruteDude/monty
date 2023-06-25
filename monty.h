#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct stack_queue_wrapper
{
	int SQ_flag;
	stack_t *head;
	stack_t *tail;
} SQW;

typedef instruction_t ist;

#define STACK_F 0
#define QUEUE_F 1

#define PALL 0
#define PINT 1
#define PCHAR 2
#define PSTR 3

#define isintlit(x) (isdigit(x) || (x) == '-' || (x) == '+')
#define UU_VAR	\
		__attribute__((__unused__))
#define MALLOC_CHECK(var) \
if (var == NULL) \
	fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE)

/* wrapper_functions.c */
stack_t *push_new(int element);
stack_t *pop_new();
stack_t *iterator(stack_t *current);
void free_SQW();
void debug_print_SQW();

/* stack_operations.c */
void push_ist(stack_t **stack, unsigned int line_number);
void pop_ist(stack_t **stack, unsigned int line_number);
void swap_ist(stack_t **stack, unsigned int line_number);
void nop_ist(stack_t **stack, unsigned int line_number);

/* stack_modifiers.c */
void rotl_ist(stack_t **stack, unsigned int line_number);
void rotr_ist(stack_t **stack, unsigned int line_number);
void stack_ist(stack_t **stack, unsigned int line_number);
void queue_ist(stack_t **stack, unsigned int line_number);

/* stack_arithmetic.c */
void add_ist(stack_t **stack, unsigned int line_number);
void sub_ist(stack_t **stack, unsigned int line_number);
void mul_ist(stack_t **stack, unsigned int line_number);
void div_ist(stack_t **stack, unsigned int line_number);
void mod_ist(stack_t **stack, unsigned int line_number);

/* stack_printers.c */
void pall_ist(stack_t **stack, unsigned int line_number);
void pint_ist(stack_t **stack, unsigned int line_number);
void pchar_ist(stack_t **stack, unsigned int line_number);
void pstr_ist(stack_t **stack, unsigned int line_number);


extern SQW global_wrapper;
#endif