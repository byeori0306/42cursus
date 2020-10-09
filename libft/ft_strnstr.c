/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:06:27 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/09 16:28:24 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
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
					break;
			}
			if (j == strlen(needle))
				return &((char *)haystack)[i];
		}
		i++;
	}
	
	return NULL;
}

int main(void)
{
	char *haystack = "Don't make me sad.";
	char *needle = "me";

	printf("%s\n", strnstr(haystack, needle, 15));
	printf("%s\n", ft_strnstr(haystack, needle, 15));
}
