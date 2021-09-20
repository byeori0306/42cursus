/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:58:50 by dahpark           #+#    #+#             */
/*   Updated: 2021/09/20 09:06:33 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_num(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == FALSE)
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	print_error(t_table *tb, char *msg)
{
	ft_putstr_fd(msg, STDERR);
	return (-1);
}

static char *get_msg(int num)
{
	char *msg;

	if (num == DIE)
		msg = "died";
	else if (num == TAKE_FORK)
		msg = "has taken a fork";
	else if (num == EATING)
		msg = "is eating";
	else if (num == SLEEPING)
		msg = "is sleeping";
	else if (num == THINKING)
		msg = "is thinking";
	return (msg);
}

int	print_status(t_table *tb, t_philo_info *p_info, long time, int status)
{
	int		lock_res;
	long	curr_time;

	lock_res = pthread_mutex_lock(&(tb->printer));
	if (lock_res != 0)
		return (print_error(tb, LOCK_ERR));
	if (time < 0)
	{
		curr_time = stopwatch(tb);
		if (curr_time < 0)
			return (-1);
		if ((status == DIE) || (status != DIE && tb->end == FALSE))
			printf("%ld %d %s\n", curr_time, p_info->id, get_msg(status));
	}
	else
	{
		if (status != DIE && tb->end == FALSE)
			printf("%ld %d %s\n", time, p_info->id, get_msg(status));
	}
	pthread_mutex_unlock(&(tb->printer));
	return (0);
}

long	stopwatch(t_table *tb)
{
	struct timeval	tv;
	long			current_time;

	if (gettimeofday(&tv, NULL) < 0)
		return (-1);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (tb->start == -1)
		tb->start = current_time;
	return (current_time - tb->start);
}
