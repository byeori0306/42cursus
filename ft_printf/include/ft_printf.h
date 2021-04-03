/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 03:29:59 by dahpark           #+#    #+#             */
/*   Updated: 2021/04/04 03:53:30 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct	s_option
{
	int		left_align;
	int		zero;
	int		width;
	int		precision;
	char	type;
}				t_option;

int				ft_printf(const char *format, ...);
int				ft_process_format(const char *format, va_list args);
int				ft_process_args(char type, t_option option, va_list args);
int				ft_process_option(int i, const char *format, \
		t_option *option, va_list args);
int				ft_print_char(char c, t_option option);
int				ft_print_string(char *str, t_option option);
int				ft_print_int(int num, t_option option);
int				ft_print_unsigned_int(unsigned int num, t_option option);
int				ft_print_hex(unsigned int num, t_option option, \
		int letter_case);
int				ft_print_pointer(unsigned long long num, t_option option);
int				ft_print_percent(t_option option);
t_option		ft_init_option(void);
int				ft_set_width(int i, const char *format, \
		va_list args, t_option *opt);
int				ft_set_prec(int i, const char *format, \
		va_list args, t_option *opt);
int				ft_consider_align(char *str, int len, t_option opt, int minus);
int				ft_consider_c_align(char c, t_option opt);
int				ft_consider_prec(char *num, int len, t_option opt, int minus);
int				ft_consider_width(int width, t_option opt, int minus);
int				ft_cal_width(int width, int prec, int len, int minus);
int				ft_cal_str_width(int width, int prec, int len);
int				ft_is_specifier(char c);
int				ft_is_option(char c);
int				ft_is_width(char c);
int				ft_is_num_type(char c);
int				ft_putchar(char c);
int				ft_putstr(char *s);
char			*ft_utoa(unsigned int n);
char			*ft_lldtoa(long long int n);
char			*ft_convert_hex(unsigned long long num, int letter_case);

#endif
