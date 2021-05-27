#include "../../push_swap.h"

void	reverse_rotate(t_list *x)
{
	int temp;

	temp = x->head->value;
	del_front(x);
	add_back(x, temp);
}

void	rra(t_list *a, int n)
{
	int i;
	int temp;

	i = 0;
	while (n > i)
	{
		temp = a->head->value;
		del_front(a);
		add_back(a, temp);
		write(1, "rra\n", 4);
		i++;
	}
}

void	rrb(t_list *b, int n)
{
	int i;
	int temp;

	i = 0;
	while (n > i)
	{
		temp = b->head->value;
		del_front(b);
		add_back(b, temp);
		write(1, "rrb\n", 4);
		i++;
	}
}
