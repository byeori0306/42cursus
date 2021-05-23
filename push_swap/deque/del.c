#include "../push_swap.h"
#include <stdlib.h>

void	del_front(t_deque *dq)
{
	t_node *h_node;

	if (is_empty(dq))
		return;
	h_node = dq->head;
	dq->head = dq->head->next;
	free(h_node);
	if (dq->head == NULL)
		dq->tail = NULL;
	else
		dq->head->prev = NULL;
	(dq->num_of_d)--;
}

void	del_back(t_deque *dq)
{
	t_node *t_node;

	if (is_empty(dq))
		return;
	t_node = dq->tail;
	dq->tail = dq->tail->prev;
	free(t_node);
	if (dq->tail == NULL)
		dq->head = NULL;
	else
		dq->tail->next = NULL;
	(dq->num_of_d)--;
}

void	del_all(t_deque *dq)
{
	if (is_empty(dq))
		return;
	while (is_empty(dq) == FALSE)
		del_back(dq);
}
