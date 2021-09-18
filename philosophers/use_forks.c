#include "philo.h"

static  int when_only_one_philo(t_table *tb, t_philo_info *p_info)
{
    int print_res;

    while (tb->end == FALSE)
    {
        if (tb->fork[p_info->id] == VACANT)
        {
            tb->fork[p_info->id] = p_info->id;
            print_res = print_status(tb, -1, p_info->id, TAKE_FORK);
            if (print_res < 0)
                return (print_error(tb, TIME_ERR));
        }
        if (exceed_limit(p_info) == TRUE)
            return (announce_death(tb, p_info));
    }
    return (0);
}

static  int take_forks(t_table *tb, t_philo_info *p_info)
{
    int rt;
    int lt;
    int rt_lock_res;
    int lt_lock_res;
    int rt_print_res;
    int lt_print_res;
    
    rt = p_info->right;
    lt = p_info->left;
    rt_lock_res = pthread_mutex_lock(&(tb->lock[rt]));
    lt_lock_res = pthread_mutex_lock(&(tb->lock[lt]));
    if (rt_lock_res != 0 || lt_lock_res !=0)
        return (print_error(tb, LOCK_ERR));
    if (tb->fork[rt] == VACANT && tb->fork[lt] == VACANT)
    {
        tb->fork[rt] = p_info->id;
        rt_print_res = print_status(tb, -1, p_info->id, TAKE_FORK);
        tb->fork[lt] = p_info->id;
        lt_print_res = print_status(tb, -1, p_info->id, TAKE_FORK);
        if (rt_print_res < 0 || lt_print_res < 0)
            return (print_error(tb, TIME_ERR));
    }
    pthread_mutex_unlock(&(tb->lock[rt]));
    pthread_mutex_unlock(&(tb->lock[lt]));
    return (0);
}

int think_and_take_forks(t_table *tb, t_philo_info *p_info)
{
    int die;

    while (TRUE)
    {
        if (tb->num_philo == 1)
            return (when_only_one_philo(tb, p_info));
        if (take_forks(tb, p_info) < 0)
            return (-1);
        die = exceed_limit(p_info);
        if (die == TRUE)
            return (announce_death(tb, p_info));
        else if (die < 0)
            return (print_error(tb, TIME_ERR));
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
    int lt_lock_res;
    int rt_lock_res;
    int die;

    rt = p_info->right;
    lt = p_info->left;
    lt_lock_res = pthread_mutex_lock(&(tb->lock[lt]));
    rt_lock_res = pthread_mutex_lock(&(tb->lock[rt]));
    if (lt_lock_res != 0 || rt_lock_res !=0)
        return (print_error(tb, LOCK_ERR));
    tb->fork[lt] = VACANT;
    tb->fork[rt] = VACANT;
    pthread_mutex_unlock(&(tb->lock[lt]));
    pthread_mutex_unlock(&(tb->lock[rt]));
    die = exceed_limit(p_info);
     if (die == TRUE)
        return (announce_death(tb, p_info));
    else if (die < 0)
        return (print_error(tb, TIME_ERR));
    if (tb->end == TRUE)
        return (-1);
    return (0);
}