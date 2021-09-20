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

static  int create_philo(t_table *tb, t_philo_info *p_info, int i)
{
    int res;

    res = pthread_create(&(tb->philo[i]), NULL,
		routine, (void *)&p_info[i]);
	if (res != 0)
		return (print_error(tb, "pthread_create call error."));
	if (p_info[i].id % 2 == 0)
    {
		res = usleep(50);
        if (res != 0)
            return (print_error(tb, SLP_ERR));
    }
    return (0);
}

static int  join_philo(t_table *tb, t_philo_info *p_info, int i)
{
    int res;

    res = pthread_join(tb->philo[i], NULL);
	if (res != 0)
		return (print_error(tb, "pthread_join call error."));
    return (0);
}

int	invite_philos(t_table *tb)
{
	int				i;
	t_philo_info	*p_info;

	p_info = malloc(sizeof(t_philo_info) * tb->num_philo);
	write_philo_info(tb, p_info);
	i = 0;
	while (i < tb->num_philo)
	{
		if (create_philo(tb, p_info, i))
            return (-1);
		i++;
	}
	i = 0;
	while (i < tb->num_philo)
	{
		if (join_philo(tb, p_info, i))
            return (-1);
		i++;
	}
	free(p_info);
	return (0);
}