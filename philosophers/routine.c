/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:21:25 by dahpark           #+#    #+#             */
/*   Updated: 2021/09/20 18:41:44 by dahpark          ###   ########.fr       */
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
	print_status(tb, p_info, curr_time, EATING);
	while (curr_time - start_eating < tb->time_eat)
	{
		curr_time = stopwatch(tb);
		if (curr_time < 0)
			return (print_error(tb, TIME_ERR));
		if (exit_routine(tb, p_info) < 0)
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
	print_status(tb, p_info, curr_time, SLEEPING);
	while (curr_time - start_sleeping < tb->time_sleep)
	{
		curr_time = stopwatch(tb);
		if (curr_time < 0)
			return (print_error(tb, TIME_ERR));
		if (exit_routine(tb, p_info) < 0)
			return (-1);
	}
	return (0);
}

static int	start_thinking(t_table *tb, t_philo_info *p_info)
{
	int	print_res;

	print_res = print_status(tb, p_info, -1, THINKING);
	if (print_res < 0)
		return (print_error(tb, TIME_ERR));
	return (0);
}

void	*routine(void *philo_info)
{
	t_philo_info	*p_info;
	t_table			*tb;
	int				count;
	int				res;

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
		res = usleep(1000);
		if (res != 0)
		{
			print_error(tb, SLP_ERR);
			break;
		}
		if (start_thinking(tb, p_info) < 0)
			break ;
	}
	return (0);
}