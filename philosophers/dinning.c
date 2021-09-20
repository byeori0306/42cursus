/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:14:46 by dahpark           #+#    #+#             */
/*   Updated: 2021/09/20 18:26:54 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
