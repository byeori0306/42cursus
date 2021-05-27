#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define INT_MAX 2147483647

typedef struct	s_node
{
	int	value;
	struct	s_node	*prev;
	struct	s_node	*next;
}		t_node;

typedef	struct	s_list
{
	int	size;
	struct	s_node	*head;
	struct	s_node	*tail;
}		t_list;

void	init_list(t_list *dq);
int	is_empty(t_list *dq);
void	add_front(t_list *dq, int num);
void	add_back(t_list *dq, int num);
void	del_front(t_list *dq);
void	del_back(t_list *dq);
void	del_all(t_list *dq);

void	push(t_list *from, t_list *to);
int	pa(t_list *a, t_list *b, int n);
int	pb(t_list *a, t_list *b, int n);
void	swap(t_list *x);
void	sa(t_list *a);
void	sb(t_list *b);
void	rotate(t_list *x);
int	ra(t_list *a, int n);
int	rb(t_list *b, int n);
void	reverse_rotate(t_list *x);
void	rra(t_list *a, int n);
void	rrb(t_list *b, int n);

void	error();
int	is_int(char **argv);
int	is_over_int(char *str);
int	is_dup(t_node *x);
t_list	fill_deque(int argc, char **argv);

int	find_median(t_list *x, int n);
void	sort_3(t_list *x);
void	sort_a_3(t_list *a);
void	sort_b_3(t_list *b);
void	sort_5(t_list *a, t_list *b);
void	a_to_b(t_list *a, t_list *b, int n);
void	b_to_a(t_list *a, t_list *b, int n);
//void	quick_sort(t_list *a, t_list *b, int n);

void	print_q(t_node *node);

#endif
