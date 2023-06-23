#include "main.h"

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

stack_t *pop_new(SQW *wpr)
{
	stack_t *popped = NULL;

	if (wpr->SQ_flag == STACK_F)
	{
		if (wpr->tail == NULL)
			return (NULL);
		/*
			fprintf(stderr, "L%d: can't pop an empty stack", wpr->line_no),
			exit(EXIT_FAILURE);
		*/
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
		/*
			fprintf(stderr, "L%d: can't pop an empty stack", wpr->line_no),
			exit(EXIT_FAILURE);
		*/
		popped = wpr->head;
		if (popped == wpr->tail)
			free(wpr->tail), wpr->head = wpr->tail = NULL;
		else
			wpr->head = popped->next;
	}
	return (popped);
}

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
