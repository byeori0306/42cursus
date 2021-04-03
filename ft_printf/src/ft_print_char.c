/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:29:45 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/03 16:45:48 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_consider_c_align(char c, t_option opt)
{
	int cnt;
	int width;

	cnt = 0;
	width = opt.width;
	if (opt.left_align == 1)
		cnt += ft_putchar(c);
	if (width > 0)
	{
		width = ft_cal_str_width(width, opt.precision, 1);
		cnt += ft_consider_width(width, opt, 0);
	}
	if (opt.left_align == 0)
		cnt += ft_putchar(c);
	return (cnt);
}

int			ft_print_char(char c, t_option option)
{
	int cnt;

	cnt = ft_consider_c_align(c, option);
	return (cnt);
}
