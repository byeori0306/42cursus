#include "../ft_printf.h"
#include <stdlib.h>

int ft_cal_str_width(int width, int precision, int len)
{
	if (precision >= 0 && precision < len)
		return (width - precision);
	else
		return (width - len);
}

int	ft_print_str_width(int n_pad, t_option option)
{
	int cnt;

	cnt = 0;
	while (n_pad > 0)
	{
		cnt += ft_putchar(' ');
		n_pad--;
	}
	return (cnt);
}

int	ft_print_str(char *str, int len, t_option option)
{
	int cnt;
	int prec;

	cnt = 0;
	prec = option.precision;
	
	// precision
	if (prec > 0 && prec < len)
	{
		while (prec > cnt)
			cnt += ft_putchar(str[cnt]);
	}
	else
		cnt += ft_putstr(str);	

	return (cnt);
}

int	ft_print_string(char *str, t_option option)
{
	int len;
	int cnt;
	int width;
	
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	cnt = 0;
	width = option.width;
	
	if (option.precision == 0)
		return (cnt = ft_print_str_width(width, option));
	
	if (option.left_align == 1)
		cnt += ft_print_str(str, len, option);
	if (width > 0)
	{
		width = ft_cal_str_width(width, option.precision, len);
		cnt += ft_print_str_width(width, option);
	}
	if (option.left_align == 0)
		cnt += ft_print_str(str, len, option);

	return (cnt);
}
