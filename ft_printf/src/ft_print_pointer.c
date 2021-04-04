/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:47:30 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/04 14:24:32 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>

static int	ft_consider_ptr_prec(char *str, int len, t_option opt, int empty)
{
	int cnt;
	int prec;

	cnt = 0;
	prec = opt.precision;
	if (!(opt.left_align == 0 && opt.zero == 1) || opt.width == 0)
		ft_putstr("0x");
	if (prec > 0)
	{
		prec -= len;
		while (prec > 0)
		{
			cnt += ft_putchar('0');
			prec--;
		}
	}
	if (empty == 0)
		cnt += ft_putstr(str);
	return (cnt);
}

static int	ft_consider_ptr_align(char *str, int len, t_option opt, int empty)
{
	int cnt;
	int width;

	cnt = 0;
	width = opt.width;
	if (opt.left_align == 1)
		cnt += ft_consider_ptr_prec(str, len, opt, empty);
	if (width > 0)
	{
		if (opt.left_align == 0 && opt.zero == 1)
			ft_putstr("0x");
		width = ft_cal_width(width, opt.precision, len, 0);
		cnt += ft_consider_width(width - 2, opt, 0);
	}
	if (opt.left_align == 0)
		cnt += ft_consider_ptr_prec(str, len, opt, empty);
	return (cnt + 2);
}

int			ft_print_pointer(unsigned long long num, t_option option)
{
	char	*p_str;
	int		p_len;
	int		cnt;
	int		empty;

	empty = 0;
	if (!(p_str = ft_convert_hex(num, 0)))
		return (-1);
	if (num == 0 && option.precision == 0)
	{
		empty = 1;
		p_len = 0;
	}
	else
		p_len = ft_strlen(p_str);
	cnt = ft_consider_ptr_align(p_str, p_len, option, empty);
	free(p_str);
	return (cnt);
}
