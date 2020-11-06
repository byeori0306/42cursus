/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:22:32 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/05 21:40:38 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	if (!lst || !f || !del)
		return (0);

	t_list *new_lst;
	if ((new_lst = ft_lstnew((*f)(lst->content))) == NULL)
		return (0);
	t_list *node;

	lst = lst->next;
	node = new_lst;
	while (lst)
	{
		if ((node->next = ft_lstnew((*f)(lst->content))) == NULL)
			ft_lstclear(&new_lst, del);
		lst = lst->next;
		node = node->next;
	}
	return (new_lst);
}
