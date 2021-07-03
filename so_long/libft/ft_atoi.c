/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:17:12 by dahpark           #+#    #+#             */
/*   Updated: 2020/10/21 15:21:34 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONG_MAX 9223372036854775807

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + *str++ - '0';
	if (sign == 1 && result > LONG_MAX)
		return (-1);
	else if (sign == -1 && (result - 1) > LONG_MAX)
		return (0);
	else
		return ((int)result * sign);
}
