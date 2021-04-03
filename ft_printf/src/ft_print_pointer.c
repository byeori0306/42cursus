/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:47:30 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/03 16:45:30 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>

static int	ft_consider_ptr_prec(char *str, int len, t_option opt)
{
	int cnt;
	int prec;

	cnt = 0;
	prec = opt.precision;
	ft_putstr("0x");
	if (prec > 0)
	{
		prec = prec - len;
		while (prec > cnt)
			cnt += ft_putchar('0');
	}
	cnt += ft_putstr(str);
	return (cnt + 2);
}

static int	ft_consider_ptr_align(char *str, int len, t_option opt)
{
	int cnt;
	int width;

	cnt = 0;
	width = opt.width;
	if (opt.left_align == 1)
		cnt += ft_consider_ptr_prec(str, len, opt);
	if (width > 0)
	{
		width = ft_cal_width(width, opt.precision, len + 2, 0);
		cnt += ft_consider_width(width, opt, 0);
	}
	if (opt.left_align == 0)
		cnt += ft_consider_ptr_prec(str, len, opt);
	return (cnt);
}

int			ft_print_pointer(unsigned long long address, t_option option)
{
	char	*p_str;
	int		p_len;
	int		cnt;

	if (address == 0 && option.precision == 0)
	{
		cnt += ft_consider_width(option.width - 2, option, 0);
		cnt += ft_putstr("0x");
		return (cnt);
	}
	if (!(p_str = ft_convert_hex(address, 0)))
		return (-1);
	p_len = ft_strlen(p_str);
	cnt = ft_consider_ptr_align(p_str, p_len, option);
	free(p_str);
	return (cnt);
}
