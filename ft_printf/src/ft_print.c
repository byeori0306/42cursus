#include "../ft_printf.h"
#include <stdio.h>

int	ft_print_char(t_option option)
{
	int cnt;

	cnt = 0;
	printf("C");
	return (cnt);
}

int	ft_print_string(t_option option)
{
	int cnt;

	cnt = 0;
	printf("S");
	return (cnt);
}

int	ft_print_pointer(t_option option)
{
	int cnt;

	cnt = 0;
	printf("P");
	return (cnt);
}

int	ft_print_percent(t_option option)
{
	int cnt;

	cnt = 0;
	ft_putchar('%');
	return (cnt);
}
