#include "../ft_printf.h"

int	ft_print_percent(t_option option)
{
	int cnt;
	int width;

	cnt = 0;
	width = option.width;
	if (option.left_align == 1)
		cnt += ft_putchar('%');
	if (width > 0)
	{
		width = ft_cal_width(width, option.precision, 1, 0);
		cnt += ft_print_width(width, 0, option);
	}
	if (option.left_align == 0)
		cnt += ft_putchar('%');

	return (cnt);
}
