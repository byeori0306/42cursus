#include "../push_swap.h"

int	is_over_int(char *str)
{
	int sign;
	unsigned long long num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		sign = 1;
		str++;
	}
	while (*str)
	{
		num = num * 10 + *str++ - '0';
		if (sign == 1 && num > INT_MAX)
			return (TRUE);
		else if (sign == -1 && (num - 1) > INT_MAX)
			return (TRUE);
	}
	return (FALSE);
}

int	is_int(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+' || ft_isdigit(argv[i][j]))
			j++;
		else
			return (FALSE);
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return (FALSE);
			j++;
		}
		if (is_over_int(argv[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_dup(t_node *x)
{
	t_node *temp;
	int num;

	temp = x;
	num = x->data;
	while (x->next)
	{
		x = x->next;
		if (x->data == num)
			return (TRUE);
	}
	if (temp->next)
		if (is_dup(temp->next) == TRUE)
			return (TRUE);
	return (FALSE);
}
