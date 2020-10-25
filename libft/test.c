#include "libft.h"
#include <stdio.h>

int main(void)
{
	t_list *lst = ft_lstnew("0");
	t_list *node_1 = ft_lstnew("1");
	t_list *node_2 = ft_lstnew("2");
	t_list *node_3 = ft_lstnew("3");

	ft_lstadd_front(&lst, node_1);
	ft_lstadd_front(&lst, node_2);
	ft_lstadd_back(&lst, node_3);

	printf("size : %d\n", ft_lstsize(lst));
	
	t_list *last = ft_lstlast(lst);

	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}

	printf("last = %s\n", last->content);
}
