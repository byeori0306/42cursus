/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:14:46 by dahpark           #+#    #+#             */
/*   Updated: 2021/09/20 18:16:36 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	write_philo_info(t_table *tb, t_philo_info *p_info)
{
	int	i;

	i = 0;
	while (i < tb->num_philo)
	{
		p_info[i].id = (i + 1);
		p_info[i].right = i % tb->num_philo;
		p_info[i].left = (i + 1) % tb->num_philo;
		p_info[i].last_meal = 0;
		p_info[i].table = tb;
		i++;
	}
}

int	prepare_forks(t_table *tb)
{
	int	i;
	int	res;

	i = 0;
	while (i < tb->num_philo)
	{
		res = pthread_mutex_init(&(tb->lock[i]), NULL);
		if (res != 0)
			return (print_error(tb, INIT_ERR));
		tb->fork[i] = VACANT;
		i++;
	}
	return (0);
}

int	invite_philos(t_table *tb)
{
	int				i;
	int				res;
	t_philo_info	*p_info;

	p_info = malloc(sizeof(t_philo_info) * tb->num_philo);
	write_philo_info(tb, p_info);
	i = 0;
	while (i < tb->num_philo)
	{
		res = pthread_create(&(tb->philo[i]), NULL,
				routine, (void *)&p_info[i]);
		if (res != 0)
			return (print_error(tb, "pthread_create call error."));
		if (p_info[i].id % 2 == 0)
			usleep(50);
		i++;
	}
	i = 0;
	while (i < tb->num_philo)
	{
		res = pthread_join(tb->philo[i], NULL);
		if (res != 0)
			return (print_error(tb, "pthread_join call error."));
		i++;
	}
	free(p_info);
	return (res);
}

int	finish_dinning(t_table *tb)
{
	int	i;

	i = 0;
	while (i < tb->num_philo)
	{
		pthread_mutex_destroy(tb->lock);
		i++;
	}
	pthread_mutex_destroy(&(tb->printer));
	pthread_mutex_destroy(&(tb->death));
	if (tb->philo)
		free(tb->philo);
	if (tb->fork)
		free(tb->fork);
	if (tb->lock)
		free(tb->lock);
	return (0);
}
