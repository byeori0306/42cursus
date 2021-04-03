/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_consider_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:36:55 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/03 15:37:08 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_consider_prec(char *num, int len, t_option option, int minus)
{
	int cnt;
	int prec;

	cnt = 0;
	prec = option.precision;
	if (minus == 1 && (!(option.left_align == 0 && option.zero == 1) \
				|| option.width == 0))
		cnt += ft_putchar('-');
	if (prec > 0)
	{
		prec -= len;
		while (prec > 0)
		{
			cnt += ft_putchar('0');
			prec--;
		}
	}
	cnt += ft_putstr(num);
	return (cnt);
}
