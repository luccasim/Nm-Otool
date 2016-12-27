/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:19:30 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:52:29 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static long long			get_arg(va_list ap, int flags)
{
	if (flags == 'l')
		return (va_arg(ap, long));
	else if (flags == 'L')
		return (va_arg(ap, long long));
	else if (flags == 'z')
		return (va_arg(ap, size_t));
	else if (flags == 'j')
		return (va_arg(ap, intmax_t));
	else if (flags == 'h')
		return ((short)va_arg(ap, int));
	else if (flags == 'H')
		return ((char)va_arg(ap, int));
	else
		return (va_arg(ap, int));
}

static unsigned long long	get_number(long long num)
{
	unsigned long long	nbr;

	if (num < 0)
		nbr = -num;
	else
		nbr = num;
	return (nbr);
}

static void					integer_rules(t_printf_flags *flags)
{
	if (flags->setting)
	{
		if (flags->FLAGS_ZERO && flags->FLAGS_DASH)
			flags->FLAGS_ZERO = 0;
		if (flags->precision != -1)
			flags->FLAGS_ZERO = 0;
	}
}

static void					write_integer(long long nb, t_printf_flags *flags)
{
	char	*sign;

	sign = NULL;
	if (nb < 0)
		sign = "-";
	else if (flags->FLAGS_PLUS)
		sign = "+";
	else if (flags->FLAGS_SPACE)
		sign = " ";
	ft_printf_join(flags, sign);
}

int							ft_printf_integer(va_list ap)
{
	t_printf_flags	*flags;
	long long		nbr;

	flags = get_printf_flags(GET_FLAGS);
	nbr = get_arg(ap, flags->length);
	ft_printf_putnbr(get_number(nbr), 10, flags->conversion);
	integer_rules(flags);
	write_integer(nbr, flags);
	return (0);
}
