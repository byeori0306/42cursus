#include "../../push_swap.h"

void	push(t_list *from, t_list *to)
{
	if (is_empty(from))
		return ;
	add_back(to, from->tail->value);
	del_back(from);
}

int	pa(t_list *a, t_list *b, int n)
{
	int i;

	i = 0;
	while (n > i)
	{
		if (is_empty(b))
			return (0);
		add_back(a, b->tail->value);
		del_back(b);
		write(1, "pa\n", 3);
		i++;
	}
	return (n);
}

int	pb(t_list *a, t_list *b, int n)
{
	int i;

	i = 0;
	while (n > i)
	{
		if (is_empty(a))
			return (0);
		add_back(b, a->tail->value);
		del_back(a);
		write(1, "pb\n", 3);
		i++;
	}
	return (n);
}
