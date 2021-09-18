#include "philo.h"

static  int eating(t_table *tb, t_philo_info *p_info)
{
    long start_eating;

    start_eating = stopwatch(tb);
    p_info->last_meal = start_eating;
    print_status(tb, p_info->id, EATING);
    while (stopwatch(tb) - start_eating < tb->time_eat)
    {
        if (exceed_limit(p_info) == TRUE)
            return (announce_death(tb, p_info));
        if (tb->end == TRUE)
            return (-1);
    }
    return (0);
}

static  int sleeping(t_table *tb, t_philo_info *p_info)
{
    long long start_sleeping;

    start_sleeping = stopwatch(tb);;
    print_status(tb, p_info->id, SLEEPING);
    while (stopwatch(tb) - start_sleeping < tb->time_sleep)
    {
        if (exceed_limit(p_info) == TRUE)
            return (announce_death(tb, p_info));
        if (tb->end == TRUE)
            return (-1);
    }
    return (0);
}

static void start_thinking(t_table *tb, int id)
{
    print_status(tb, id, THINKING);
}

void    *routine(void *philo_info)
{
    t_philo_info *p_info;
    t_table *tb;
    int count;

    p_info = (t_philo_info *)philo_info;
    tb = p_info->table;
    count = p_info->table->num_eat;
    while (count--)
    {
        if (think_and_take_forks(tb, p_info) < 0)
            break;
        if (eating(tb, p_info) < 0)
            break;
        if (put_forks(tb, p_info) < 0)
            break;
        if (sleeping(tb, p_info) < 0)
            break;
        start_thinking(tb, p_info->id);
    }
    return (0);
}