/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:00:33 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/04 03:28:28 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_option	ft_init_option(void)
{
	t_option	option;

	option.left_align = 0;
	option.zero = 0;
	option.width = 0;
	option.precision = -1;
	return (option);
}

int			ft_set_width(int i, const char *format, va_list args, t_option *opt)
{
	int temp;

	temp = 0;
	if (format[i] == '*')
	{
		if ((opt->width = va_arg(args, int)) < 0)
		{
			opt->left_align = 1;
			opt->width *= -1;
		}
		i++;
	}
	else
	{
		while (ft_isdigit(format[i]))
		{
			temp = temp * 10;
			temp += format[i++] - '0';
		}
		opt->width = temp;
	}
	return (i);
}

int			ft_set_prec(int i, const char *format, va_list args, t_option *opt)
{
	int temp;

	temp = 0;
	opt->precision = 0;
	if (format[i] == '*')
	{
		opt->precision = va_arg(args, int);
		i++;
	}
	else if (format[i] == '-')
	{
		opt->precision = -1;
		i++;
	}
	else
	{
		while (ft_isdigit(format[i]))
		{
			temp = temp * 10;
			temp += format[i++] - '0';
		}
		opt->precision = temp;
	}
	return (i);
}
