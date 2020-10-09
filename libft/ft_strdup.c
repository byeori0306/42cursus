/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:30:30 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/09 16:42:46 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *ft_strdup(const char *s1)
{
	char *dup;
	int len;
	int i;

	len = strlen(s1);
	if ((dup = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return NULL;

	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}

	return dup;
}

int main(void)
{
	char *s = "white chocolate latte";

	printf("%s\n", ft_strdup(s));
}
