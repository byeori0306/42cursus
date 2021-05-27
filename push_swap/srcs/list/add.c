#include "../push_swap.h"
#include <stdlib.h>

void	add_front(t_list *dq, int num)
{
	t_node *node;

	if ((node = malloc(sizeof(t_node))) == NULL)
		return;
	node->value = num;
	node->next = dq->head;
	if (is_empty(dq))
		dq->tail = node;
	else
		dq->head->prev = node;
	node->prev = NULL;
	dq->head = node;
	(dq->size)++;
}

void	add_back(t_list *dq, int num)
{
	t_node *node;

	if ((node = malloc(sizeof(t_node))) == NULL)
		return;
	node->value = num;
	node->prev = dq->tail;
	if (is_empty(dq))
		dq->head = node;
	else
		dq->tail->next = node;
	node->next = NULL;
	dq->tail = node;
	(dq->size)++;
}
