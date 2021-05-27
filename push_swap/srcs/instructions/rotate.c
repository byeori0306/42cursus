#include "../../push_swap.h"

void	rotate(t_list *x)
{
	int temp;

	temp = x->tail->value;
	del_back(x);
	add_front(x, temp);
}

int	ra(t_list *a, int n)
{
	int i;
	int temp;
	
	i = 0;
	while (n > i)
	{
		temp = a->tail->value;
		del_back(a);
		add_front(a, temp);
		write(1, "ra\n", 3);
		i++;
	}
	return (n);
}

int	rb(t_list *b, int n)
{
	int i;
	int temp;

	i = 0;
	while (n > i)
	{
		temp = b->tail->value;
		del_back(b);
		add_front(b, temp);
		write(1, "rb\n", 3);
		i++;
	}
	return (n);
}
