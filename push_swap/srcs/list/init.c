#include "../push_swap.h"

void	init_list(t_list *dq)
{
	dq->head = NULL;
	dq->tail = NULL;
	dq->size = 0;
}

int	is_empty(t_list *dq)
{
	if (dq->head == NULL)
		return TRUE;
	else
		return FALSE;
}
