/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_consider_align.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:37:59 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/03 15:39:28 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_consider_align(char *str, int len, t_option opt, int minus)
{
	int cnt;
	int width;

	cnt = 0;
	width = opt.width;
	if (opt.left_align == 1)
		cnt += ft_consider_prec(str, len, opt, minus);
	if (width > 0)
	{
		width = ft_cal_width(width, opt.precision, len, minus);
		cnt += ft_consider_width(width, opt, minus);
	}
	if (opt.left_align == 0)
		cnt += ft_consider_prec(str, len, opt, minus);
	return (cnt);
}
