/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:54:26 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/03 13:56:09 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>

static	unsigned int	get_len(long long int n)
{
	unsigned int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char					*ft_lldtoa(long long int n)
{
	unsigned int	i;
	unsigned int	len;
	char			*arr;

	i = 0;
	if (n < 0)
		n = n * -1;
	len = get_len(n);
	if ((arr = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	if (n == 0)
		arr[0] = '0';
	while (n > 0)
	{
		arr[len - (i++) - 1] = (n % 10 + '0');
		n /= 10;
	}
	arr[len] = '\0';
	return (arr);
}
