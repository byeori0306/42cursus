#include "../ft_printf.h"
#include <stdio.h>

int	ft_set_width(int i, const char *format, va_list args, t_option *option)
{
	int temp;

	temp = 0;
	if (format[i] == '*')
	{
		if ((option->width = va_arg(args, int)) < 0)
		{
			option->left_align = 1;
			option->width *= -1;
		}
		i++;
	}
	else
	{
		while (ft_isdigit(format[i]))
		{
			temp = temp * 10;
			temp += format[i++] - '0';
		}
		option->width = temp;
	}
	return (i);
}

int	ft_set_precision(int i, const char *format, va_list args, t_option *option)
{
	int temp;

	temp = 0;
	if (format[i] == '*')
	{
		option->precision = va_arg(args, int);
		i++;
	}
	else
	{
		while (ft_isdigit(format[i]))
		{
			temp = temp * 10;
			temp += format[i++] - '0';
		}
		option->precision = temp;
	}
	return (i);
}
