/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:35:34 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/04 15:39:41 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((result = (char *)malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
		return (0);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcpy(&result[len1], s2, len2 + 1);
	result[len1 + len2] = '\0';
	return (result);
}
