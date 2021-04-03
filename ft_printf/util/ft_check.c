/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:47:37 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/03 14:44:11 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_is_specifier(char c)
{
	char *spec;

	spec = "cspdiuxX%";
	while (*spec)
	{
		if (*spec == c)
			return (1);
		spec++;
	}
	return (0);
}

char	*ft_is_option(char c)
{
	return (ft_strchr("-0.", c));
}

char	*ft_is_width(char c)
{
	return (ft_strchr("123456789*", c));
}
