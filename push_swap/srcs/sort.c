#include "../push_swap.h"
#include <stdio.h>

void	prt(t_list *a, t_list *b)
{
	t_node *x = a->head;
	t_node *y = b->head;

	printf("a : ");
	while (x)
	{
		printf("%d ", x->value);
		x = x->next;
	}
	printf("\n");
	printf("b : ");
	while (y)
	{
		printf("%d ", y->value);
		y = y->next;
	}
	printf("\n");
	printf("-------------------------------\n");
}

void	a_to_b(t_list *a, t_list *b, int n)
{
	int pivot;
	int n_ra;
	int n_pb;
	int i;

	if (n <= 2)
	{
		if (n == 2)
		{
			if (a->tail->value > a->tail->prev->value)
				sa(a);
		}
		//else if (n == 3)
		//	sort_a_3(a);
		return;
	}
	pivot = find_median(a, n);
	n_ra = 0;
	n_pb = 0;
	i = 0;
	while (n > i)
	{
		if (a->tail->value > pivot)
			n_ra += ra(a, 1);
		else
			n_pb += pb(a, b, 1);
		i++;
	}
	rra(a, n_ra);
	//prt(a, b);
	a_to_b(a, b, n_ra);
	//prt(a, b);
	b_to_a(a, b, n_pb);
	//prt(a, b);
}

void	b_to_a(t_list *a, t_list *b, int n)
{
	int pivot;
	int n_rb;
	int n_pa;
	int i;
	
	if (n <= 2)
	{
		if (n == 2)
		{
			if (b->tail < b->tail->prev)
				sb(b);
		}
		//else if (n == 3)
		//	sort_b_3(b);
		pa(a, b, n);
		return;
	}
	pivot = find_median(b, n);
	n_rb = 0;
	n_pa = 0;
	i = 0;
	while (n > i)
	{
		if (b->tail->value < pivot)
			n_rb += rb(b, 1);
		else
			n_pa += pa(a, b, 1);
		i++;
	}
	rrb(b, n_rb);
	//prt(a, b);
	a_to_b(a, b, n_pa);
	//prt(a, b);
	b_to_a(a, b, n_rb);
	//prt(a, b);
}

void	quick_sort(t_list *a, t_list *b, int n)
{
	int pivot;
	int n_pb = 0;
	int n_ra = 0;
	int i;

	i = 0;
	if (n == 1)
		return;
	if (n == 2)
	{
		if (a->tail->value < a->tail->prev->value)
			sa(a);
		return;
	}
	pivot = find_median(a, n);
	while (n > i)
	{
		if (a->tail->value > pivot)
			n_pb += pb(a, b, 1);
		else
			n_ra += ra(a, 1);
		i++;
	}
	rra(a, n - n_pb);
	pa(a, b, n_pb);
	quick_sort(a, b, n_pb);
	ra(a, n_pb);
	quick_sort(a, b, n - n_pb);
	rra(a, n_pb);
}
