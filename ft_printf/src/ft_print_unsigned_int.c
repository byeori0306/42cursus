/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:21:49 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/03 16:41:50 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>

int	ft_print_unsigned_int(unsigned int num, t_option option)
{
	char	*n_str;
	int		n_len;
	int		cnt;

	if (num == 0 && option.precision == 0)
		return (cnt = ft_consider_width(option.width, option, 0));
	if (!(n_str = ft_utoa(num)))
		return (-1);
	n_len = ft_strlen(n_str);
	cnt = ft_consider_align(n_str, n_len, option, 0);
	free(n_str);
	return (cnt);
}
