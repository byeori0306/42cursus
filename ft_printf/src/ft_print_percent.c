/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:30:43 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/03 16:42:03 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_consider_pct_align(t_option opt)
{
	int cnt;
	int width;

	cnt = 0;
	width = opt.width;
	if (opt.left_align == 1)
		cnt += ft_putchar('%');
	if (width > 0)
	{
		width = ft_cal_width(width, opt.precision, 1, 0);
		cnt += ft_consider_width(width, opt, 0);
	}
	if (opt.left_align == 0)
		cnt += ft_putchar('%');
	return (cnt);
}

int			ft_print_percent(t_option option)
{
	int cnt;

	cnt = ft_consider_pct_align(option);
	return (cnt);
}
