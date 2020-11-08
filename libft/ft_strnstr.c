/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:06:27 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/08 17:29:04 by dahpark          ###   ########.fr       */
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
	while (i < len && haystack[i] != '\0')
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
		i++;
	}
	return (0);
}
