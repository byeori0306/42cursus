#include "../push_swap.h"
#include <stdio.h>
void	sort_5(t_list *a, t_list *b)
{
	int m;
	int i;
	
	m = find_median(a, 5);
	i = 0;
	while (i < 5)
	{
		if (a->tail->value < m)
			pb(a, b, 1);
		else
			ra(a, 1);
		i++;
	}
	sort_3(a);
	if (b->tail->value < b->head->value)
		sb(b);
	pa(a, b, 2);
}
