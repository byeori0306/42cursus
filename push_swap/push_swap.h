#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define INT_MAX 2147483647

typedef struct	s_node
{
	int	data;
	struct	s_node	*prev;
	struct	s_node	*next;
}		t_node;

typedef	struct	s_deque
{
	int	num_of_d;
	struct	s_node	*head;
	struct	s_node	*tail;
}		t_deque;

void	init_deque(t_deque *dq);
int	is_empty(t_deque *dq);
void	add_front(t_deque *dq, int num);
void	add_back(t_deque *dq, int num);
void	del_front(t_deque *dq);
void	del_back(t_deque *dq);
void	del_all(t_deque *dq);

void	push(t_deque *x, t_deque *y);
void	swap(t_deque *x);
void	rotate(t_deque *x);
void	reverse_rotate(t_deque *x);

void	error();
int	is_int(char **argv);
int	is_over_int(char *str);
int	is_dup(t_node *x);
t_deque	fill_deque(int argc, char **argv);

#endif
