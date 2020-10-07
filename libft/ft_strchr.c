/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:58:42 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/07 15:16:24 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			break;
		s++;
	}
	
	return (char *)s;
}

int main(void)
{
	const char *s = "Be happy";
	int c = 'c';

	printf("%s", ft_strchr(s, c));
}
