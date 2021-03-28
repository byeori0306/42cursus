#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>
#include <ctype.h>

t_flag	ft_init_flag(t_flag flag)
{
	flag.specifier = 0;
	flag.left_align = 0;
	flag.zero = 0;
	flag.star = 0;
	flag.width = 0;
	flag.precision = 0;
}

int	ft_parse_flag(const char *format, int i, t_flag flag)
{
	while (format[i])
	{
		if (!ft_is_specifier(format[i]) && !ft_is_flag(format[i]) && !ft_isdigit(format[i]))
			break;
		if (format[i] == '-')
			printf("-\n"); //flag.left_align = 1;
		else if (format[i] == '0')
			printf("0\n"); //flag.zero = 1;
		else if (format[i] == '*')
			printf("*\n"); //flag.star = 1;
		else if (format[i] == '.')
			printf(".\n"); //flag.precision = 1;
		else if (ft_is_specifier(format[i]))
		{
			flag.specifier = format[i]; // need?
			break;
		}
		i++;
	}

	return (i);
}

int	ft_process_args(char specifier, t_flag flag, va_list args)
{
	int cnt;

	cnt = 0;

	if (specifier == 'c')
		cnt = ft_print_char(flag);
	else if (specifier == 's')
		cnt = ft_print_string(flag);
	else if (specifier == 'p')
		cnt = ft_print_pointer(flag);
	else if (specifier == 'd' || specifier == 'i')
		cnt = ft_print_int(flag);
	else if (specifier == 'u')
		cnt = ft_print_un_int(flag);
	else if (specifier == 'x')
		cnt = ft_print_hex(flag);
	else if (specifier == 'X')
		cnt = ft_print_hex(flag);
	else if (specifier == '%')
		cnt = ft_print_percent(flag);

	return (cnt);
}

int	ft_process_format(const char *format, va_list args)
{
	int cnt;
	int i;
	t_flag flag;
	
	cnt = 0;
	i = 0;
	
	while (format[i])
	{
		flag = ft_init_flag(flag);
		if (format[i] != '%')
			cnt += ft_putchar(format[i]);
		else if (format[i] == '%')
		{
			i = ft_parse_flag(format, ++i, flag);
			if (ft_is_specifier(format[i]))
				cnt += ft_process_args(format[i], flag, args);
			else // need?
				cnt += ft_putchar(format[i]);	
		}
		format++;
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
