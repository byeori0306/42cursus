#include "../philo.h"

int is_num(char *str)
{
    while (*str)
    {
        if (ft_isdigit(*str) == FALSE)
            return (FALSE);
        str++;
    }
    return (TRUE);
}

int print_error(t_table *tb, char *msg)
{
    ft_putstr_fd(msg, STDERR);
    return (-1);
}

int    print_status(t_table *tb, long time, int id, char *msg)
{
    int lock_res;
    int curr_time;

    lock_res = pthread_mutex_lock(&(tb->printer));
    if (lock_res != 0)
        return (print_error(tb, LOCK_ERR));
    if (time < 0)
    {
        curr_time = stopwatch(tb);
        if (curr_time < 0)
            return (-1);
        printf("%ld %d %s\n", stopwatch(tb), id, msg);
    }
    else
        printf("%ld %d %s\n", time, id, msg);
    pthread_mutex_unlock(&(tb->printer));
    return (0);
}

long stopwatch(t_table *tb)
{
    struct  timeval tv;
    long current_time;

    if (gettimeofday(&tv, NULL) < 0)
        return (-1);
    current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    if (tb->start == -1)
        tb->start = current_time;
    return (current_time - tb->start);
}