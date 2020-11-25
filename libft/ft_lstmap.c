/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:22:32 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/25 15:58:32 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *elem;

	if (!lst || !f)
		return (0);
	if ((new_lst = ft_lstnew((*f)(lst->content))) == NULL)
		return (0);
	lst = lst->next;
	elem = new_lst;
	while (lst)
	{
		if ((elem->next = ft_lstnew((*f)(lst->content))) == NULL)
			ft_lstclear(&new_lst, del);
		lst = lst->next;
		elem = elem->next;
	}
	return (new_lst);
}
