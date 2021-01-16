/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:06:27 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/15 14:51:59 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needle_len;
	size_t i;
	size_t j;

	i = 0;
	needle_len = ft_strlen(needle);
	while (1)
	{
		if (needle_len == 0 || haystack[i] == needle[0])
		{
			j = 0;
			while ((i + j) < len && j < needle_len)
			{
				if (haystack[i + j] == needle[j])
					j++;
				else
					break ;
			}
			if (j == needle_len)
				return (&((char *)haystack)[i]);
		}
		if (haystack[i] == '\0' || i > len)
			return (0);
		i++;
	}
}
