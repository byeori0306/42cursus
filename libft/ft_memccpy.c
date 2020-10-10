/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:34:16 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/10 14:47:53 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *temp;
	const unsigned char *s;
	int i;

	temp = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		temp[i] = s[i];
		if (s[i] == (char)c)
			break;
		i++;
	}

	if (i == n)
		return NULL;
	else
		return &dst[++i];
}

int main(void)
{
	char dst[] = "Make a cake";
	char src[] = "sour cream";

	printf("%s\n", ft_memccpy(dst, src, 'c', 7));
}
