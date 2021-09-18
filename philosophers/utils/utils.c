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
    ft_putstr_fd(msg, 2);
    finish_dinning(tb);
    return (-1);
}

void    print_status(t_table *tb, int id, char *msg) // 뮤텍스 추가
{
    pthread_mutex_lock(&(tb->printer));
    printf("%ld %d %s\n", stopwatch(tb), id, msg);
    pthread_mutex_unlock(&(tb->printer));
}

long stopwatch(t_table *tb)
{
    struct  timeval tv;
    long current_time;

    gettimeofday(&tv, NULL);
    current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    if (tb->start == -1)
        tb->start = current_time;
    return (current_time - tb->start);
}