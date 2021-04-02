#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

t_option	ft_init_option(void)
{
	t_option	option;

	option.left_align = 0;
	option.zero = 0;
	option.width = 0;
	option.precision = -1;

	return (option);
}

int	ft_process_option(int i, const char *format, t_option *option, va_list args)
{
	while (format[i])
	{
		if (!ft_is_specifier(format[i]) && !ft_is_option(format[i]) && !ft_is_width(format[i]))
			break;
		if (format[i] == '-')
			option->left_align = 1;
		if (format[i] == '0')
			option->zero = 1;
		if (ft_is_width(format[i]))
			i = ft_set_width(i, format, args, option);
		if (format[i] == '.')
			i = ft_set_precision(++i, format, args, option);
		if (ft_is_specifier(format[i]))
			break;
		i++;
	}
	return (i);
}

int	ft_process_args(char type, t_option option, va_list args)
{
	int cnt;

	cnt = 0;

	if (type == 'c')
		cnt = ft_print_char(va_arg(args, char), option);
	else if (type == 's')
		cnt = ft_print_string(va_arg(args, char *), option);
	else if (type == 'p')
		cnt = ft_print_pointer(va_arg(args, unsigned long long), option);
	else if (type == 'd' || type == 'i')
		cnt = ft_print_int(va_arg(args, int), option);
	else if (type == 'u')
		cnt = ft_print_unsigned_int(va_arg(args, unsigned int), option);
	else if (type == 'x')
		cnt = ft_print_hex(va_arg(args, unsigned int), option, 0);
	else if (type == 'X')
		cnt = ft_print_hex(va_arg(args, unsigned int), option, 1);
	else if (type == '%')
		cnt = ft_print_percent(option);

	return (cnt);
}

int	ft_process_format(const char *format, va_list args)
{
	int cnt;
	int i;
	t_option option;
	
	cnt = 0;
	i = 0;
	
	while (format[i])
	{
		if (format[i] == '%')
		{
			option = ft_init_option();
			i = ft_process_option(++i, format, &option, args);
			if (ft_is_specifier(format[i]))
				cnt += ft_process_args(format[i], option, args);
		}
		else // format[i] != % 
			cnt += ft_putchar(format[i]);
		i++;
	}

	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	int cnt;
	va_list args;
	
	cnt = 0;
	va_start(args, format);
	cnt = ft_process_format(format, args);

	va_end(args);

	return (cnt);
}
