#include "../ft_printf.h"
#include <stdio.h>

int	ft_print_char(t_flag flag)
{
	int cnt;

	cnt = 0;
	printf("C");
	return (cnt);
}

int	ft_print_string(t_flag flag)
{
	int cnt;

	cnt = 0;
	printf("S");
	return (cnt);
}

int	ft_print_pointer(t_flag flag)
{
	int cnt;

	cnt = 0;
	printf("P");
	return (cnt);
}

int	ft_print_int(t_flag flag)
{
	int cnt;

	cnt = 0;
	printf("I");
	return (cnt);
}

int	ft_print_un_int(t_flag flag)
{
	int cnt;

	cnt = 0;
	printf("UI");
	return (cnt);
}

int	ft_print_hex(t_flag flag)
{
	int cnt;

	cnt = 0;
	printf("H");
	return (cnt);
}

int	ft_print_percent(t_flag flag)
{
	int cnt;

	cnt = 0;
	ft_putchar('%');
	return (cnt);
}
