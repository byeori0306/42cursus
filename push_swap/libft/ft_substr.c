/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:06:01 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/14 20:26:28 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if ((sub = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	if (start >= ft_strlen(s))
		sub[0] = '\0';
	else
		ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
