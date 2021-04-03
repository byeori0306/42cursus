/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:47:37 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/04 03:24:53 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_check(char *list, char c)
{
	while (*list)
	{
		if (*list == c)
			return (1);
		list++;
	}
	return (0);
}

int			ft_is_specifier(char c)
{
	return (ft_check("cspdiuxX%", c));
}

int			ft_is_num_type(char c)
{
	return (ft_check("diuxXp", c));
}

int			ft_is_option(char c)
{
	return (ft_check("-0.", c));
}

int			ft_is_width(char c)
{
	return (ft_check("123456789*", c));
}
