/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:06:10 by dahpark           #+#    #+#             */
/*   Updated: 2020/11/24 16:31:45 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	unsigned int	get_len(int n)
{
	unsigned int num;
	unsigned int len;

	if (n <= 0)
	{
		len = 1;
		num = n * -1;
	}
	else
	{
		len = 0;
		num = n;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char					*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	num;
	char			*arr;

	i = 0;
	len = get_len(n);
	if ((arr = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	if (n < 0)
		num = n * -1;
	else
		num = n;
	if (n == 0)
		arr[0] = '0';
	else if (n < 0)
		arr[0] = '-';
	while (num > 0)
	{
		arr[len - (i++) - 1] = (num % 10 + '0');
		num /= 10;
	}
	arr[len] = '\0';
	return (arr);
}
