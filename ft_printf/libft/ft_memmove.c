/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:48:36 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/13 22:12:34 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*temp;
	const unsigned char	*s;

	temp = dst;
	s = src;
	if (dst == NULL && src == NULL)
		return (0);
	if (dst <= src)
	{
		while (len--)
			*temp++ = *s++;
	}
	else
	{
		temp += len;
		s += len;
		while (len--)
			*--temp = *--s;
	}
	return (dst);
}
