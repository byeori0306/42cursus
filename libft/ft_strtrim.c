/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:43:19 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/08 19:20:43 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		head;
	int		tail;
	int		len;
	char	*result;

	head = 0;
	tail = ft_strlen(s1) - 1;
	while (s1[head] && ft_strchr(set, s1[head]))
		head++;
	while (tail >= 0 && ft_strchr(set, s1[tail]))
		tail--;
	len = tail - head + 1;
	if (len <= 0)
		return (ft_strdup(""));
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = s1[head + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
