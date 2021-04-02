#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

typedef	struct	s_option
{
	int type;
	int left_align;
	int zero;
	int star;
	int width;
	int precision;
}	t_option;

int	ft_printf(const char *format, ...);
int	ft_process_format(const char *format, va_list args);
int	ft_process_args(char type, t_option option, va_list args);
int	ft_process_option(int i, const char *format, t_option *option, va_list args);
char	*ft_is_specifier(char c);
char	*ft_is_option(char c);
char	*ft_is_width(char c);
int	ft_putchar(char c);
int	ft_putstr(char *s);

int ft_set_width(int i, const char *format, va_list args, t_option *option);
int ft_set_precision(int i, const char *format, va_list args, t_option *option);

int	ft_cal_width(int width, int precision, int len, int minus);
int	ft_print_width(int width, int minus, t_option option);
int	ft_print_num(char *num, int len, int minus, t_option option);
int	ft_cal_str_width(int width, int precision, int len);
int	ft_print_str_width(int n_pad, t_option option);
int ft_print_str(char *str, int len, t_option option);
char *ft_utoa(unsigned int n);
int ft_get_hex_len(unsigned long long num);
char *ft_convert_hex(unsigned long long num, int letter_case);
int	ft_print_ptr(char *str, int len, t_option option);

int	ft_print_int(int num, t_option option);
int	ft_print_unsigned_int(unsigned int num, t_option option);
int ft_print_percent(t_option option);
int	ft_print_hex(unsigned int num, t_option option, int letter_case);
int	ft_print_string(char *str, t_option option);
int	ft_print_char(char c, t_option option);
int	ft_print_pointer(unsigned long long address, t_option option);

void	ft_print_option(t_option option);

#endif
