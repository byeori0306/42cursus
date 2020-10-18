/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 10:13:55 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/18 14:23:17 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		get_arr_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			len++;
			while (*s && *s != c)
				s++;
		}
		if (*s == c)
			s++;
	}
	return (len);
}

int		get_str_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c)
	{
		s++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		arr_len;
	int		str_len;
	char	**arr;

	arr_len = get_arr_len(s, c);
	if ((arr = (char **)malloc(sizeof(char *) * (arr_len + 1))) == NULL)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str_len = get_str_len(&(*s), c);
			if ((arr[i] = (char *)malloc(sizeof(char) * (str_len + 1))) == NULL)
				return (0);
			j = 0;
			while (*s && *s != c)
				arr[i][j++] = *s++;
			arr[i][j] = '\0';
			i++;
		}
		if (*s == c)
			s++;
	}
	arr[arr_len] = 0;
	return (arr);
}
/*
int main(void)
{
	char *s = "0a0aa0aaa0aaaa";
	char c = '0';
	int i = 0;
	char **result = ft_split(s, c);

	while (result[i])
	{
		printf("result #%d : %s\n", i, result[i]);
		i++;
	}
}
*/
