/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:06:42 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/08 21:10:20 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *src;

	src = s;
	while (n--)
	{
		if (*src == (unsigned char)c)
			return (void *)src;
		src++;
	}
	return (0);
}
