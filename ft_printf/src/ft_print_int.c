#include "../ft_printf.h"
#include <stdlib.h>

int ft_cal_width(int width, int precision, int len, int minus)
{
	if (minus == 1)
		width -= 1;
	if (precision >= len)
		return (width - precision);
	else
		return (width - len);
}

int	ft_print_width(int n_pad, int minus, t_option option)
{
	char padding;
	int cnt;

	cnt = 0;
	if (option.left_align == 0 && option.zero == 1)
	{
		if (minus == 1)
			cnt += ft_putchar('-');
		padding = '0';
	}
	else
		padding = ' ';
	while (n_pad > 0)
	{
		cnt += ft_putchar(padding);
		n_pad--;
	}
	return (cnt);
}
#include <stdio.h>
int	ft_print_num(char *num, int len, int minus, t_option option)
{
	int cnt;

	cnt = 0;
	
	// minus
	if (minus == 1 && (!(option.left_align == 0 && option.zero == 1) || option.width == 0))
		cnt += ft_putchar('-');
	// precision
	if (option.precision > 0)
	{
		option.precision = option.precision - len;
		while (option.precision > 0)
		{
			cnt += ft_putchar('0');
			option.precision -= 1;
		}
	}
	// num
	cnt += ft_putstr(num);	

	return (cnt);
}

int	ft_print_int(int num, t_option option)
{
	char *n_str;
	int n_len;
	int cnt;
	int minus;
	int width;

	minus = 0;
	if (num == 0 && option.precision == 0)
		return (cnt = ft_print_width(option.width, minus, option));
	if (num < 0)
		minus = 1;
	n_str = ft_lldtoa((long long int)num);
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
