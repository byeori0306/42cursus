/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:48:36 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/10 15:05:18 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *temp;
	const unsigned char *s;

	temp = dst;
	s = src;
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
	return dst;
}

int main(void)
{
	char array[10];

	memset(array, 0, sizeof(array));
	strcpy(array, "test");
	printf("original : %s\n", array);
	memmove(array+2, array, strlen("test"));
	printf("after memmove : %s\n", array);
	return 0;
}
