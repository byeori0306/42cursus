#include "../push_swap.h"

void	init_deque(t_deque *dq)
{
	dq->head = NULL;
	dq->tail = NULL;
	dq->num_of_d = 0;
}

int	is_empty(t_deque *dq)
{
	if (dq->head == NULL)
		return TRUE;
	else
		return FALSE;
}
