/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:18:55 by dahpark           #+#    #+#             */
/*   Updated: 2021/09/20 18:10:27 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exceed_limit(t_philo_info *p_info)
{
	t_table	*tb;
	long	curr_time;

	tb = p_info->table;
	curr_time = stopwatch(tb);
	if (curr_time < 0)
		return (print_error(tb, TIME_ERR));
	if (curr_time - p_info->last_meal > tb->limit)
		return (TRUE);
	return (FALSE);
}

int	announce_death(t_table *tb, t_philo_info *p_info)
{
	int	lock_res;
	int	print_res;

	lock_res = pthread_mutex_lock(&(tb->death));
	if (lock_res != 0)
		return (print_error(tb, LOCK_ERR));
	if (tb->end == FALSE)
	{
		tb->end = 1;
		print_res = print_status(tb, p_info, -1, DIE);
		if (print_res < 0)
			return (print_error(tb, TIME_ERR));
	}
	pthread_mutex_unlock(&(tb->death));
	return (-1);
}

int	exit_routine(t_table *tb, t_philo_info *p_info)
{
	int	die;

	die = exceed_limit(p_info);
	if (die == TRUE)
		return (announce_death(tb, p_info));
	else if (die < 0)
		return (print_error(tb, TIME_ERR));
	if (tb->end == TRUE)
		return (-1);
	return (0);
}
