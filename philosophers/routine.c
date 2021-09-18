/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:21:25 by dahpark           #+#    #+#             */
/*   Updated: 2021/09/18 23:32:42 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating(t_table *tb, t_philo_info *p_info)
{
	long	start_eating;
	long	curr_time;
	int		die;

	start_eating = stopwatch(tb);
	curr_time = start_eating;
	p_info->last_meal = start_eating;
	print_status(tb, curr_time, p_info->id, EATING);
	while (curr_time - start_eating < tb->time_eat)
	{
		curr_time = stopwatch(tb);
		if (curr_time < 0)
			return (print_error(tb, TIME_ERR));
		die = exceed_limit(p_info);
		if (die == TRUE)
			return (announce_death(tb, p_info));
		else if (die < 0)
			return (print_error(tb, TIME_ERR));
		if (tb->end == TRUE)
			return (-1);
	}
	return (0);
}

static int	sleeping(t_table *tb, t_philo_info *p_info)
{
	long	start_sleeping;
	long	curr_time;
	int		die;

	start_sleeping = stopwatch(tb);
	curr_time = start_sleeping;
	print_status(tb, curr_time, p_info->id, SLEEPING);
	while (curr_time - start_sleeping < tb->time_sleep)
	{
		curr_time = stopwatch(tb);
		if (curr_time < 0)
			return (print_error(tb, TIME_ERR));
		die = exceed_limit(p_info);
		if (die == TRUE)
			return (announce_death(tb, p_info));
		else if (die < 0)
			return (print_error(tb, TIME_ERR));
		if (tb->end == TRUE)
			return (-1);
	}
	return (0);
}

static int	start_thinking(t_table *tb, int id)
{
	int	print_res;

	print_res = print_status(tb, -1, id, THINKING);
	if (print_res < 0)
		return (print_error(tb, TIME_ERR));
	return (0);
}

void	*routine(void *philo_info)
{
	t_philo_info	*p_info;
	t_table			*tb;
	int				count;

	p_info = (t_philo_info *)philo_info;
	tb = p_info->table;
	count = p_info->table->num_eat;
	while (count--)
	{
		if (think_and_take_forks(tb, p_info) < 0)
			break ;
		if (eating(tb, p_info) < 0)
			break ;
		if (put_forks(tb, p_info) < 0)
			break ;
		if (sleeping(tb, p_info) < 0)
			break ;
		if (start_thinking(tb, p_info->id) < 0)
			break ;
	}
	return (0);
}
