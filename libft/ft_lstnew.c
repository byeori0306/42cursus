/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:26:36 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/01 17:09:32 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *node;

	if ((node = malloc(sizeof(t_list))) == NULL)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}
