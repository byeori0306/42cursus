#include "../push_swap.h"

void	push(t_deque *x, t_deque *y)
{
	if (is_empty(y))
		return ;
	add_back(x, y->tail->data);
	del_back(y);
}

void	swap(t_deque *x)
{
	int temp;
	
	if (x->num_of_d <= 1)
		return ;
	temp = x->tail->data;
	x->tail->data = x->tail->prev->data;
	x->tail->prev->data = temp;
}

void	rotate(t_deque *x)
{
	int temp;

	temp = x->tail->data;
	del_back(x);
	add_front(x, temp);
}

void	reverse_rotate(t_deque *x)
{
	int temp;

	temp = x->head->data;
	del_front(x);
	add_back(x, temp);
}
