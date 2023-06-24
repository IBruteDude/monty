#include "monty.h"

/**
 * push_new - pushs a new element on the underlying linked list
 *
 * @wpr: input S/Q wrapper address
 * @element: the value of the new pushed element
 * Return: a pointer to the pushed element
 */
stack_t *push_new(SQW *wpr, int element)
{
	stack_t *tail;

	tail = malloc(sizeof(stack_t));
	MALLOC_CHECK(tail);
	tail->prev = wpr->tail, tail->next = NULL, tail->n = element;
	wpr->tail = tail;
	if (wpr->head == NULL)
		wpr->head = wpr->tail;
	return (tail);
}

/**
 * pop_new - pops a new element off the underlying linked list
 *
 * @wpr: input S/Q wrapper address
 * Return: a pointer to the popped element
 */
stack_t *pop_new(SQW *wpr)
{
	stack_t *popped = NULL;

	if (wpr->SQ_flag == STACK_F)
	{
		if (wpr->tail == NULL)
			return (NULL);
		popped = wpr->tail;
		if (popped == wpr->head)
			free(wpr->head), wpr->head = wpr->tail = NULL;
		else
			wpr->tail = popped->prev;
	}
	else
	{
		if (wpr->head == NULL)
			return (NULL);
		popped = wpr->head;
		if (popped == wpr->tail)
			free(wpr->tail), wpr->head = wpr->tail = NULL;
		else
			wpr->head = popped->next;
	}
	return (popped);
}

/**
 * iterator - an iterator abstraction over the S/Q wrapper
 *
 * @wpr: input S/Q wrapper address
 * @current: the current iteration element address
 * Return: teh next iteration element address
 */
stack_t *iterator(SQW *wpr, stack_t *current)
{
	if (current == NULL)
		switch (wpr->SQ_flag)
		{
		case STACK_F:
			return (wpr->tail);
		case QUEUE_F:
			return (wpr->head);
		}
	else
		switch (wpr->SQ_flag)
		{
		case STACK_F:
			return (current->prev);
		case QUEUE_F:
			return (current->next);
		}
	return (NULL);
}
