/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 10:13:55 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/21 20:27:20 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**fill_arr(char **arr, char const *s, char c)
{
	int i;
	int j;
	int str_len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str_len = get_str_len(&(*s), c);
			if ((arr[i] = (char *)malloc(sizeof(char) * (str_len + 1))) == NULL)
			{
				free_arr(arr);
				return (0);
			}
			j = 0;
			while (*s && *s != c)
				arr[i][j++] = *s++;
			arr[i][j] = '\0';
			i++;
		}
		if (*s == c)
			s++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		arr_len;
	char	**arr;

	arr_len = get_arr_len(s, c);
	if ((arr = (char **)malloc(sizeof(char *) * (arr_len + 1))) == NULL)
		return (0);
	if (fill_arr(arr, s, c) == NULL)
		return (0);
	arr[arr_len] = 0;
	return (arr);
}
