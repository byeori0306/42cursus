/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:15:52 by dahpark           #+#    #+#             */
/*   Updated: 2021/09/18 22:50:07 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	basic_check(int argc, char **argv)
{
	int	i;

	if (!(argc == 5 || argc == 6))
	{
		printf("You need 4 or 5 arguments.\n");
		return (-1);
	}
	i = 1;
	while (i < argc)
	{
		if (is_num(argv[i]) == FALSE)
		{
			printf("The arguments should be positive number.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	set_table(int argc, char **argv, t_table *tb)
{
	int	init_res_1;
	int	init_res_2;

	if (argc == 6)
		tb->num_eat = ft_atoi(argv[5]);
	else
		tb->num_eat = -1;
	tb->num_philo = ft_atoi(argv[1]);
	tb->limit = ft_atoi(argv[2]);
	tb->time_eat = ft_atoi(argv[3]);
	tb->time_sleep = ft_atoi(argv[4]);
	tb->start = -1;
	tb->end = FALSE;
	tb->philo = malloc(sizeof(pthread_t) * tb->num_philo);
	tb->fork = malloc(sizeof(int) * tb->num_philo);
	tb->lock = malloc(sizeof(pthread_mutex_t) * tb->num_philo);
	init_res_1 = pthread_mutex_init(&(tb->printer), NULL);
	init_res_2 = pthread_mutex_init(&(tb->death), NULL);
	if (!(tb->philo) || !(tb->fork) || !(tb->lock))
		return (print_error(tb, "Check arguments value."));
	if (init_res_1 != 0 || init_res_2 != 0)
		return (print_error(tb, INIT_ERR));
	return (0);
}

static int	check_table(t_table *tb)
{
	int	res;

	res = 0;
	if (tb->num_philo > 200)
		res = print_error(tb, "Too many philosopher.");
	if (tb->time_eat < 60 || tb->time_sleep < 60 || tb->limit < 60)
		res = print_error(tb, "Philosophers need at least 60ms.");
	return (res);
}

int	init(int argc, char **argv, t_table *tb)
{
	if (basic_check(argc, argv) < 0)
		return (-1);
	if (set_table(argc, argv, tb) < 0)
		return (-1);
	return (check_table(tb));
}
