#include "../ft_printf.h"
#include <stdlib.h>

int	ft_print_ptr(char *str, int len, t_option option)
{
	int cnt;
	int prec;

	cnt = 0;
	prec = option.precision;

	ft_putstr("0x");	
	// precision
	if (prec > 0)
	{
		prec = prec - len;
		while (prec > cnt)
			cnt += ft_putchar('0');
	}
	cnt += ft_putstr(str);

	return (cnt + 2);
}

int	ft_print_pointer(unsigned long long address, t_option option)
{
	char *p_str;
	int p_len;
	int cnt;
	int width;
	
	cnt = 0;
	width = option.width;
	if (address == 0 && option.precision == 0)
	{
		cnt += ft_print_width(width - 2, 0, option);
		cnt += ft_putstr("0x");
		return (cnt);
	}
	p_str = ft_convert_hex(address, 0);
	p_len = ft_strlen(p_str);
	
	if (option.left_align == 1)
		cnt += ft_print_ptr(p_str, p_len, option);
	if (width > 0)
	{
		width = ft_cal_width(width, option.precision, p_len + 2, 0);
		cnt += ft_print_width(width, 0, option);
	}
	if (option.left_align == 0)
		cnt += ft_print_ptr(p_str, p_len, option);
	free(p_str);
	return (cnt);
}
