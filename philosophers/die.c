#include "philo.h"

int exceed_limit(t_philo_info *p_info)
{
    t_table *tb;

    tb = p_info->table;
    if (stopwatch(tb) - p_info->last_meal > tb->limit)
        return (TRUE);
    return (FALSE);
}

int announce_death(t_table *tb, t_philo_info *p_info)
{
    pthread_mutex_lock(&(tb->death));
    if (tb->end == FALSE)
    {
        tb->end = 1;
        print_status(tb, p_info->id, DIED);
    }
    pthread_mutex_unlock(&(tb->death));
    return (-1);
}