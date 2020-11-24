/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 10:13:55 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/24 13:18:42 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		get_arr_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len++;
			while (*s && *s != c)
				s++;
		}
	}
	return (len);
}

static	int		get_str_len(char const *s, char c)
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

static	void	free_arr(char **arr)
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

static	int		fill_arr(char **arr, char const *s, char c)
{
	int i;
	int j;
	int str_len;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			str_len = get_str_len(s, c);
			if (!(arr[i] = (char *)malloc(sizeof(char) * (str_len + 1))))
			{
				free_arr(arr);
				return (1);
			}
			j = 0;
			while (*s && *s != c)
				arr[i][j++] = *s++;
			arr[i][j] = '\0';
			i++;
		}
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	int		arr_len;
	char	**arr;

	arr_len = get_arr_len(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (arr_len + 1))))
		return (NULL);
	if (fill_arr(arr, s, c))
		return (NULL);
	arr[arr_len] = NULL;
	return (arr);
}
