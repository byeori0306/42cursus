#include "../ft_printf.h"
#include <stdlib.h>

int	ft_print_ptr(char *str, int len, t_option option)
{
	int cnt;
	int prec;

	cnt = 0;
	prec = option.precision;

	cnt += ft_putstr("0x");	
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

int	ft_print_pointer(unsigned long long address, t_option option)
{
	char *p_str;
	int p_len;
	int cnt;
	int width;
	
	p_str = ft_convert_hex(address, 0);
	p_len = ft_strlen(p_str) + 2;
	cnt = 0;
	width = option.width;
	
	if (option.precision == 0)
		return (cnt = ft_print_str_width(width, option));
	
	if (option.left_align == 1)
		cnt += ft_print_ptr(p_str, p_len, option);
	if (width > 0)
	{
		width = ft_cal_str_width(width, option.precision, p_len);
		cnt += ft_print_str_width(width, option);
	}
	if (option.left_align == 0)
		cnt += ft_print_ptr(p_str, p_len, option);

	return (cnt);
}
