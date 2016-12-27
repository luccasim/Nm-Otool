/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:15:01 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:59:41 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static int		write_float(t_printf_flags *flags, double f)
{
	char	*sign;

	sign = NULL;
	if (f < 0)
		sign = "-";
	else if (flags->FLAGS_PLUS)
		sign = "+";
	else if (flags->FLAGS_SPACE)
		sign = " ";
	ft_printf_join(flags, sign);
	return (0);
}

int				ft_printf_float(va_list ap)
{
	double				f;
	t_printf_flags		*flags;
	int					size;

	flags = get_printf_flags(GET_FLAGS);
	f = va_arg(ap, double);
	size = (flags->precision < 0) ? 6 : flags->precision;
	ft_printf_double(f, size, flags->conversion);
	write_float(flags, f);
	return (0);
}
