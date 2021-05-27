#include "../push_swap.h"

static int	find_max(t_list *x)
{
	int m;

	m = find_median(x, 3);
	if (x->tail->value > m)
		return (1);
	else if (x->tail->prev->value > m)
		return (2);
	else
		return (3);
}

void	sort_a_3(t_list *a)
{
	if (find_max(a) == 1)
	{
		sa(a);
		return ;
	}
	if (find_max(a) == 3)
		sa(a);
	ra(a, 1);
	sa(a);
	rra(a, 1);
	if (a->tail->value > a->tail->prev->value)
		sa(a);
}

void	sort_b_3(t_list *b)
{
	if (find_max(b) == 1)
	{
		sb(b);
		return ;
	}
	if (find_max(b) == 3)
		sa(b);
	rb(b, 1);
	sb(b);
	rrb(b, 1);
	if (b->tail->value > b->tail->prev->value)
		sa(b);
}

void	sort_3(t_list *x)
{
	int a;
	int b;
	int c;

	a = x->head->value;
	b = x->head->next->value;
	c = x->tail->value;
	if (a > b && a > c && b < c)
		sa(x);
	else if (c > a && c > b && b > a)
		sa(x);
	else if (c < a && c < b && b > a)
		sa(x);
	a = x->head->value;
	b = x->head->next->value;
	c = x->tail->value;
	if (c > a && c > b && a > b)
		ra(x, 1);
	else if (a < c && a < b && b > c)
		rra(x, 1);
}


/*void	sort_a_2(t_list *a)
{
	if (a->tail->value < a->tail->prev->value)
		sa(a);
}

void	sort_b_2(t_list *b)
{
	if (b->tail->value < b->tail->prev->value)
		sb(b);
}*/
