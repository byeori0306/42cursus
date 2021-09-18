#include "philo.h"

static  int when_only_one_philo(t_table *tb, t_philo_info *p_info)
{
    while (tb->end == FALSE)
    {
        if (tb->fork[p_info->id] == VACANT)
        {
            tb->fork[p_info->id] = p_info->id;
            print_status(tb, p_info->id, TAKE_FORK);
        }
        if (exceed_limit(p_info) == TRUE)
            return (announce_death(tb, p_info));
    }
    return (0);
}

static  void take_forks(t_table *tb, t_philo_info *p_info)
{
    int rt;
    int lt;

    rt = p_info->right;
    lt = p_info->left;
    pthread_mutex_lock(&(tb->lock[rt]));
    pthread_mutex_lock(&(tb->lock[lt]));
    if (tb->fork[rt] == VACANT && tb->fork[lt] == VACANT)
    {
        tb->fork[rt] = p_info->id;
        print_status(tb, p_info->id, TAKE_FORK);
        tb->fork[lt] = p_info->id;
        print_status(tb, p_info->id, TAKE_FORK);
    }
    pthread_mutex_unlock(&(tb->lock[rt]));
    pthread_mutex_unlock(&(tb->lock[lt]));
}

int think_and_take_forks(t_table *tb, t_philo_info *p_info)
{
    while (TRUE)
    {
        if (tb->num_philo == 1)
            return (when_only_one_philo(tb, p_info));
        take_forks(tb, p_info);
        if (exceed_limit(p_info) == TRUE)
            return (announce_death(tb, p_info));
        if (tb->end == TRUE)
            return (-1);
        if (tb->fork[p_info->right] == p_info->id && tb->fork[p_info->left] == p_info->id)
            break;
    }
    return (0);
}

int put_forks(t_table *tb, t_philo_info *p_info)
{
    int rt;
    int lt;

    rt = p_info->right;
    lt = p_info->left;
    pthread_mutex_lock(&(tb->lock[lt]));
    pthread_mutex_lock(&(tb->lock[rt]));
    tb->fork[lt] = VACANT;
    tb->fork[rt] = VACANT;
    pthread_mutex_unlock(&(tb->lock[lt]));
    pthread_mutex_unlock(&(tb->lock[rt]));
    if (exceed_limit(p_info) == TRUE)
        return (announce_death(tb, p_info));
    if (tb->end == TRUE)
        return (-1);
    return (0);
}