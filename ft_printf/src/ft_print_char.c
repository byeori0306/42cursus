#include "../ft_printf.h"

int	ft_print_char(char c, t_option option)
{
	int cnt;
	int width;

	cnt = 0;
	width = option.width;
	if (option.left_align == 1)
		cnt += ft_putchar(c);
	if (width > 0)
	{
		width = ft_cal_str_width(width, option.precision, 1);
		cnt += ft_print_str_width(width, option);
	}
	if (option.left_align == 0)
		cnt += ft_putchar(c);
	return (cnt);
}
