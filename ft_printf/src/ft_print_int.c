#include "../ft_printf.h"
#include <stdlib.h>

int	ft_putstr(char *s)
{
	int i;
	
	i = 0;
	while(s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}

	return (i);
}

int ft_cal_width(int width, int precision, int len)
{
	if (precision >= len)
		return (width - precision);
	else
		return (width - len);
}

int	ft_print_width(int width, int left_align, int zero)
{
	int cnt;

	cnt = 0;
	while (width > 0)
	{
		if (left_align == 0 && zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		cnt++;
	}
	return (cnt);
}

int	ft_print_num(char *num, int len, int minus, int precision)
{
	int cnt;

	cnt = 0;
	
	// minus
	if (minus == 1)
	{
		ft_putchar('-');
		cnt += 1;
	}

	// precision
	if (precision >= 0)
	{
		precision = precision - len;
		while (precision > 0)
		{
			ft_putchar('0');
			precision -= 1;
			cnt++;
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
	if (num < 0)
	{
		minus = 1;
		num *= -1;
	}
	n_str = ft_itoa(num);
	n_len = ft_strlen(n_str);
	width = option.width;
	cnt = 0;
	
	if (option.left_align == 1)
		cnt += ft_print_num(n_str, n_len, minus, option.precision);
	if (width > 0)
	{
		width = ft_cal_width(width, option.precision, n_len);
		cnt += ft_print_width(width, option.left_align, option.zero);
	}
	if (option.left_align == 0)
		cnt += ft_print_num(n_str, n_len, minus, option.precision);

	free(n_str);
	return (cnt);
}
