/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:34:16 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/11 13:31:11 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*s;
	int					i;

	temp = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		temp[i] = s[i];
		if (s[i] == (char)c)
			break ;
		i++;
	}
	if (i == n)
		return (0);
	else
		return (&dst[++i]);
}
