/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:24:29 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/10 16:20:10 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1;
	const unsigned char *p2;
	int i;

	i = 0;
	p1 = s1;
	p2 = s2;
	while (i < n && p1[i] == p2[i])
		i++;

	if (i == n)
		return (0);
	else
		return (p1[i] - p2[i]);
}

int main(void)
{
	char *s1 = "Is that real?";
	char *s2 = "Is this real?";

	printf("%d\n", ft_memcmp(s1, s2, 10));
}
