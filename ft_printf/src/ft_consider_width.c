/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_consider_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:35:24 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/04 03:15:34 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_cal_width(int width, int prec, int len, int minus)
{
	if (minus == 1)
		width -= 1;
	if (prec >= len)
		return (width - prec);
	else
		return (width - len);
}

int	ft_cal_str_width(int width, int prec, int len)
{
	if (prec >= 0 && prec < len)
		return (width - prec);
	else
		return (width - len);
}

int	ft_consider_width(int n_pad, t_option opt, int minus)
{
	char	padding;
	int		cnt;

	cnt = 0;
	padding = ' ';
	if (ft_is_num_type(opt.type) && opt.precision >= 0)
		opt.zero = 0;
	if (opt.left_align == 0 && opt.zero == 1)
	{
		if (minus == 1)
			cnt += ft_putchar('-');
		padding = '0';
	}
	while (n_pad > 0)
	{
		cnt += ft_putchar(padding);
		n_pad--;
	}
	return (cnt);
}
