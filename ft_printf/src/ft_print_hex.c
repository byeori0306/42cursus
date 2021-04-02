#include "../ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_print_hex(unsigned int num, t_option option, int letter_case)
{
	char *n_str;
	int n_len;
	int cnt;
	int minus;
	int width;

	minus = 0;
	if (num == 0 && option.precision == 0)
		return (cnt = ft_print_width(option.width, minus, option));
	if (!(n_str = ft_convert_hex(num, letter_case)))
		return (-1);
	n_len = ft_strlen(n_str);
	width = option.width;
	cnt = 0;
	
	if (option.left_align == 1)
		cnt += ft_print_num(n_str, n_len, minus, option);
	if (width > 0)
	{
		width = ft_cal_width(width, option.precision, n_len, minus);
		cnt += ft_print_width(width, minus, option);
	}
	if (option.left_align == 0)
		cnt += ft_print_num(n_str, n_len, minus, option);

	free(n_str);
	return (cnt);
}
