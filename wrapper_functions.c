#include "monty.h"

/**
 * push_new - pushs a new element on the underlying linked list
 *
 * @value: the value of the new pushed element
 * Return: a pointer to the pushed element
 */
stack_t *push_new(int value)
{
	stack_t *tail;
	/* static int n = 1; */

	tail = malloc(sizeof(stack_t));
	MALLOC_CHECK(tail);
	/* printf("\n========\nbefore %dth allocation\n", n), debug_print_SQW(); */
	/* printf("\n%dth allocation: %4x\n", n++, (uint8_t)(intptr_t)tail); */
	tail->prev = global_wrapper.tail, tail->next = NULL, tail->n = value;

	if (global_wrapper.head == global_wrapper.tail)
	{
		if (global_wrapper.head == NULL)
			global_wrapper.head = tail;
		else
			global_wrapper.head->next = tail;
	}
	if (global_wrapper.tail)
		global_wrapper.tail->next = tail;
	global_wrapper.tail = tail;
	return (tail);
}

/**
 * pop_new - pops a new element off the underlying linked list
 *
 * Return: a pointer to the popped element
 */
stack_t *pop_new(void)
{
	stack_t *popped = NULL;

	if (global_wrapper.SQ_flag == STACK_F)
	{
		if (global_wrapper.tail == NULL)
			return (NULL);
		popped = global_wrapper.tail;
		if (popped == global_wrapper.head)
			free(global_wrapper.head), global_wrapper.head = global_wrapper.tail = NULL;
		else
			global_wrapper.tail = popped->prev, global_wrapper.tail->next = NULL;
	}
	else
	{
		if (global_wrapper.head == NULL)
			return (NULL);
		popped = global_wrapper.head;
		if (popped == global_wrapper.tail)
			free(global_wrapper.tail), global_wrapper.head = global_wrapper.tail = NULL;
		else
			global_wrapper.head = popped->next, global_wrapper.head->prev = NULL;
	}
	return (popped);
}

/**
 * iterator - an iterator abstraction over the S/Q wrapper
 *
 * @current: the current iteration element address
 * Return: teh next iteration element address
 */
stack_t *iterator(stack_t *current)
{
	if (current == NULL)
		switch (global_wrapper.SQ_flag)
		{
		case STACK_F:
			return (global_wrapper.tail);
		case QUEUE_F:
			return (global_wrapper.head);
		}
	else
		switch (global_wrapper.SQ_flag)
		{
		case STACK_F:
			return (current->prev);
		case QUEUE_F:
			return (current->next);
		}
	return (NULL);
}

/**
 * free_SQW - frees the S/Q wrapper underlying linked lists nodes
 */
void free_SQW(void)
{
	stack_t *crt_node = global_wrapper.head, *next_node;

	/* debug_print_SQW(); */
	while (crt_node != NULL)
	{
		next_node = crt_node->next;
		/* printf("freeing %4x\n", (uint8_t)(intptr_t)crt_node); */
		free(crt_node);
		crt_node = next_node;
	}
	global_wrapper.head = global_wrapper.tail = NULL;
}
/**
 * debug_print_SQW - a debug printer for the S/Q wrapper
 */
void debug_print_SQW(void)
{
	stack_t *node = global_wrapper.head;
	int i = 0;

	if (global_wrapper.head && global_wrapper.tail)
		printf("\n/---------\nhead: %4x, next: %4x, prev: %4x\n",
			(uint8_t)(intptr_t)global_wrapper.head,
			(uint8_t)(intptr_t)global_wrapper.head->next,
			(uint8_t)(intptr_t)global_wrapper.head->prev),
		printf("tail: %4x, next: %4x, prev: %4x\n---------/\n",
			(uint8_t)(intptr_t)global_wrapper.tail,
			(uint8_t)(intptr_t)global_wrapper.tail->next,
			(uint8_t)(intptr_t)global_wrapper.tail->prev);
	else
		printf("\n/---------\nhead: %4x\ntail: %4x\n---------/\n",
			(uint8_t)(intptr_t)global_wrapper.head,
			(uint8_t)(intptr_t)global_wrapper.tail);
	while (node != NULL)
	{
		printf("-N%d: %4x\n", i, (uint8_t)(intptr_t)node);
		node = node->next, i++;
	}
}
