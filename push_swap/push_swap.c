#include "push_swap.h"
#include <stdio.h>

void	print_q(t_node *node)
{
	while (node)
	{
		printf("%d ", node->data);
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
	init_deque(&a);	
	if (argc < 2)
		return (0);

	a = fill_deque(argc, argv);
}
