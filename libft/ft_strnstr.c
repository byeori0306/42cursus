/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:06:27 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/12 18:45:47 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while ((i + j) < len)
			{
				if (haystack[i + j] == needle[j])
					j++;
				else
					break ;
			}
			if (j == ft_strlen(needle))
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (0);
}
