/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:56:42 by dahpark           #+#    #+#             */
/*   Updated: 2021/09/20 17:51:21 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define TRUE 1
# define FALSE 0
# define VACANT -1
# define STDERR 2
# define TIME_ERR "Stopwatch doesn't work."
# define INIT_ERR "pthread_mutex_init call error."
# define LOCK_ERR "pthread_mutex_lock call error."
# define TAKE_FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIE 5

typedef struct s_table
{
	long			start;
	int				end;
	int				num_philo;
	int				limit;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	pthread_t		*philo;
	int				*fork;
	pthread_mutex_t	*lock;
	pthread_mutex_t	printer;
	pthread_mutex_t	death;
}				t_table;

typedef struct s_philo_info
{
	t_table	*table;
	int		id;
	int		right;
	int		left;
	int		last_meal;
}				t_philo_info;

int		basic_check(int argc, char **argv);
int		init(int argc, char **argv, t_table *tb);
int		prepare_forks(t_table *tb);
int		invite_philos(t_table *tb);
int		finish_dinning(t_table *tb);
void	*routine(void *philo_info);
int		think_and_take_forks(t_table *tb, t_philo_info *p_info);
int		put_forks(t_table *tb, t_philo_info *p_info);
int		exceed_limit(t_philo_info *p_info);
int		announce_death(t_table *tb, t_philo_info *p_info);
int		exit_routine(t_table *tb, t_philo_info *p_info);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		is_num(char *str);
void	ft_putstr_fd(char *s, int fd);
int		print_error(t_table *tb, char *msg);
int		print_status(t_table *tb, t_philo_info *p_info, long time, int status);
long	stopwatch(t_table *tb);

#endif
