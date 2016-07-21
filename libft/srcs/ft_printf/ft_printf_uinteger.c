/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uinteger.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:31:50 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:48:24 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static unsigned long long	get_arg(va_list ap, int flags)
{
	if (flags == 'L')
		return (va_arg(ap, unsigned long long));
	else if (flags == 'j')
		return (va_arg(ap, uintmax_t));
	else if (flags == 'z')
		return (va_arg(ap, ssize_t));
	else if (flags == 'l')
		return (va_arg(ap, unsigned long int));
	else if (flags == 'h')
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (flags == 'H')
		return ((unsigned char)va_arg(ap, unsigned int));
	else
		return (va_arg(ap, unsigned int));
}

static int					get_base(char c)
{
	if (c == 'x' || c == 'X')
		return (16);
	if (c == 'o')
		return (8);
	return (10);
}

static void					u_rules(t_printf_flags *flags)
{
	if (flags->setting)
	{
		if (flags->FLAGS_ZERO && flags->FLAGS_DASH)
			flags->FLAGS_ZERO = 0;
		if (flags->precision != -1)
			flags->FLAGS_ZERO = 0;
	}
}

static void					u_write(unsigned long long n, t_printf_flags *f)
{
	char	*sign;
	int		size;

	sign = NULL;
	if (n)
	{
		if (f->conversion == 'x' && f->FLAGS_HASH)
			sign = "0x";
		else if (f->conversion == 'X' && f->FLAGS_HASH)
			sign = "0X";
		else if (f->conversion == 'o' && f->FLAGS_HASH)
		{
			size = ft_printf_tmp(NULL, 0, GET);
			if (f->precision <= size)
				sign = "0";
		}
	}
	ft_printf_join(f, sign);
}

int							ft_printf_uinteger(va_list ap)
{
	unsigned long long	nbr;
	t_printf_flags		*flags;
	int					base;

	flags = get_printf_flags(GET_FLAGS);
	nbr = get_arg(ap, flags->length);
	base = get_base(flags->conversion);
	ft_printf_putnbr(nbr, base, flags->conversion);
	u_rules(flags);
	u_write(nbr, flags);
	return (0);
}
