/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:56:42 by dahpark           #+#    #+#             */
/*   Updated: 2021/09/18 13:32:06 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define VACANT -1
#define TAKE_FORK "has taken a fork"
#define EATING "is eating"
#define SLEEPING "is sleeping"
#define THINKING "is thinking"
#define DIED "died"

typedef struct s_table
{
	long start;
	int end;
    int num_philo;
    int limit;
    int time_eat;
    int time_sleep;
	int num_eat;
	pthread_t *philo;
	int *fork;
	pthread_mutex_t *lock;
	pthread_mutex_t printer;
	pthread_mutex_t death;
}               t_table;

typedef struct  s_philo_info
{
	t_table *table;
	int id;
	int right;
	int left;
	int last_meal;
}               t_philo_info;

int init(int argc, char **argv, t_table *tb);
int prepare_forks(t_table *tb);
int invite_philos(t_table *tb);
void finish_dinning(t_table *tb);
void    *routine(void *philo_info);
int think_and_take_forks(t_table *tb, t_philo_info *p_info);
int    put_forks(t_table *tb, t_philo_info *p_info);
int exceed_limit(t_philo_info *p_info);
int announce_death(t_table *tb, t_philo_info *p_info);
int	ft_atoi(const char *str);
int ft_isdigit(int c);
int is_num(char *str);
void	ft_putstr_fd(char *s, int fd);
int print_error(t_table *tb, char *msg);
void    print_status(t_table *tb, int id, char *msg);
long stopwatch(t_table *tb);

#endif