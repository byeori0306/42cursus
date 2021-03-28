#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

typedef	struct	s_flag
{
	int specifier;
	int left_align;
	int zero;
	int star;
	int width;
	int precision;
}	t_flag;

int	ft_printf(const char *format, ...);
int	ft_process_format(const char *format, va_list args);
int	ft_process_args(char specifier, t_flag flag, va_list args);
int	ft_is_specifier(char c);
int	ft_is_flag(char c);
int	ft_putchar(char c);

int	ft_print_char(t_flag flag);
int	ft_print_string(t_flag flag);
int	ft_print_pointer(t_flag flag);
int	ft_print_int(t_flag flag);
int	ft_print_un_int(t_flag flag);
int	ft_print_hex(t_flag flag);
int	ft_print_percent(t_flag flag);

#endif
