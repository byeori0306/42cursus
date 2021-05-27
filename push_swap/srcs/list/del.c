#include "../push_swap.h"
#include <stdlib.h>

void	del_front(t_list *dq)
{
	t_node *l_node;

	if (is_empty(dq))
		return;
	l_node = dq->head;
	dq->head = dq->head->next;
	free(l_node);
	if (dq->head == NULL)
		dq->tail = NULL;
	else
		dq->head->prev = NULL;
	(dq->size)--;
}

void	del_back(t_list *dq)
{
	t_node *r_node;

	if (is_empty(dq))
		return;
	r_node = dq->tail;
	dq->tail = dq->tail->prev;
	free(r_node);
	if (dq->tail == NULL)
		dq->head = NULL;
	else
		dq->tail->next = NULL;
	(dq->size)--;
}

void	del_all(t_list *dq)
{
	if (is_empty(dq))
		return;
	while (is_empty(dq) == FALSE)
		del_back(dq);
	free(dq);
}
