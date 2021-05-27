#include "push_swap.h"
#include <stdio.h>

void	print_q(t_node *node)
{
	while (node)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

void	error()
{
	printf("Error\n");
	exit(1);
}

t_deque	fill_deque(int argc, char **argv)
{
	int i;
	t_deque dq;

	i = 1;
	init_deque(&dq);
	if (!(is_int(argv)))
		error();
	while (argc > i)
		add_back(&dq, ft_atoi(argv[i++]));
	if (is_dup(dq.head))
	{
		del_all(&dq);
		error();
	}
	return (dq);
}

int	main(int argc, char **argv)
{
	t_deque a;
	t_deque b;
	init_deque(&a);
	init_deque(&b);

	if (argc < 2)
		return (0);

	a = fill_deque(argc, argv);
	//printf("before sort :\n");
	//print_q(a.head);
	
	if (a.size == 3)
		sort_3(&a);
	else if (a.size == 5)
		sort_5(&a, &b);
	else
		a_to_b(&a, &b, a.size);
	
	//printf("after sort : \n");
	//print_q(a.head);
	//print_q(b.head);
}
