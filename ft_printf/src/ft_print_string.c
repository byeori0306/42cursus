/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:26:12 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/03 16:42:26 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>

/*int	ft_print_str_width(int n_pad, t_option option)
{
	int cnt;

	cnt = 0;
	while (n_pad > 0)
	{
		cnt += ft_putchar(' ');
		n_pad--;
	}
	return (cnt);
}*/

static int	ft_consider_str_prec(char *str, int len, t_option opt)
{
	int cnt;
	int prec;

	cnt = 0;
	prec = opt.precision;
	if (prec > 0 && prec < len)
	{
		while (prec > cnt)
			cnt += ft_putchar(str[cnt]);
	}
	else
		cnt += ft_putstr(str);
	return (cnt);
}

static int	ft_consider_str_align(char *str, int len, t_option opt)
{
	int cnt;
	int width;

	cnt = 0;
	width = opt.width;
	if (opt.left_align == 1)
		cnt += ft_consider_str_prec(str, len, opt);
	if (width > 0)
	{
		width = ft_cal_str_width(width, opt.precision, len);
		cnt += ft_consider_width(width, opt, 0);
	}
	if (opt.left_align == 0)
		cnt += ft_consider_str_prec(str, len, opt);
	return (cnt);
}

int			ft_print_string(char *str, t_option option)
{
	int len;
	int cnt;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (option.precision == 0)
		return (cnt = ft_consider_width(option.width, option, 0));
	cnt = ft_consider_str_align(str, len, option);
	return (cnt);
}
