/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:29:52 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 18:00:45 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

# include "ft_printf.h"
# include <unistd.h>

# define GET			0
# define SET			1
# define SEND			2
# define NBR_SIZE		31
# define BUF_READ 		1
# define BUF_WRITE 		2
# define BUF_CHAR 		4
# define BUF_COLOR	 	8
# define BUF_SIZE		1000
# define RESET_FLAGS	0
# define GET_FLAGS 		1
# define FLAGS_HASH 	flags[0]
# define FLAGS_DASH 	flags[1]
# define FLAGS_PLUS 	flags[2]
# define FLAGS_SPACE	flags[3]
# define FLAGS_ZERO 	flags[4]

typedef struct	s_func
{
	int			(*ptrfunc)(va_list);
	char		key;
}				t_func;

typedef struct	s_printf_flags
{
	int			flags[5];
	int			width;
	int			precision;
	char		length;
	char		conversion;
	int			setting;
}				t_printf_flags;

int				ft_printf_fd(int fd, int act);
int				ft_printf_color(char *str, va_list ap);
int				ft_printf_long(va_list ap);
int				ft_printf_bin(va_list ap);
int				ft_printf_tmp(char *str, int size, int act);
int				ft_printf_join(t_printf_flags *flags, char *sign);
void			ft_printf_margin(char c, int a);
int				ft_printf_putdouble(double f, int size);
int				ft_printf_double_scient(double f, int size);
double			ft_printf_pow(int base, int pow);
int				ft_printf_double(double f, int size, char conversion);
int				ft_printf_number(va_list ap);
int				ft_printf_strequ(char *s1, char *s2);
int				ft_printf_atoi(char **arg);
int				ft_printf_buffer(char *str, int act);
int				ft_printf_lexer(char *str, va_list ap);
int				ft_printf_date(va_list ap);
int				ft_printf_integer(va_list ap);
int				ft_printf_uinteger(va_list ap);
int				ft_printf_percentage(va_list ap);
int				ft_printf_string(va_list ap);
int				ft_printf_char(va_list ap);
int				ft_printf_float(va_list ap);
int				ft_printf_wchar(int c);
int				ft_printf_address(va_list ap);
int				ft_printf_bin(va_list ap);
t_printf_flags	*get_printf_flags(int action);
int				set_printf_flags(char *arg, t_printf_flags *flags);
int				set_printf_width(char *a, va_list ap, t_printf_flags *f);
int				set_printf_length(char *arg, t_printf_flags *flags);
int				set_printf_precision(char *a, va_list ap, t_printf_flags *f);
int				set_printf_conversion(char *arg, t_printf_flags *flags);
int				ft_printf_wstring(va_list ap, t_printf_flags *flags);
int				ft_printf_conversion(va_list ap, t_printf_flags *f);
int				ft_printf_putnbr(unsigned long long n, int b, int c);

#endif
