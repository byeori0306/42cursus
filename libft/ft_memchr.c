/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:06:42 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/10 15:23:49 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *src;

	src = s;
	while (n--)
	{
		if (*src++ == c)
			return (void *)src;
	}
	return (0);
}

int main(void)
{
	char *s = "Don't be afraid";

	printf("%s", ft_memchr(s, 'b', 10));
}
