/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:07:01 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/03 15:46:39 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>

int	ft_print_int(int num, t_option option)
{
	char	*n_str;
	int		n_len;
	int		cnt;
	int		minus;

	minus = 0;
	if (num == 0 && option.precision == 0)
		return (cnt = ft_consider_width(option.width, option, minus));
	if (num < 0)
		minus = 1;
	if (!(n_str = ft_lldtoa((long long int)num)))
		return (-1);
	n_len = ft_strlen(n_str);
	cnt = ft_consider_align(n_str, n_len, option, minus);
	free(n_str);
	return (cnt);
}
