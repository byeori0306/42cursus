#include "../../push_swap.h"

void	swap(t_list *x)
{
	int temp;
	
	if (x->size <= 1)
		return ;
	temp = x->tail->value;
	x->tail->value = x->tail->prev->value;
	x->tail->prev->value = temp;
}

void	sa(t_list *a)
{
	int temp;
	
	if (a->size <= 1)
		return ;
	temp = a->tail->value;
	a->tail->value = a->tail->prev->value;
	a->tail->prev->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_list *b)
{
	int temp;
	
	if (b->size <= 1)
		return ;
	temp = b->tail->value;
	b->tail->value = b->tail->prev->value;
	b->tail->prev->value = temp;
	write(1, "sb\n", 3);
}
