/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:29:31 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:55:03 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static void	string_rules(t_printf_flags *flags, char *str)
{
	if (str)
	{
		if (!*str)
			flags->precision = 0;
	}
}

int			ft_printf_string(va_list ap)
{
	char				*str;
	t_printf_flags		*flags;
	int					size;

	flags = get_printf_flags(GET_FLAGS);
	if (flags->length == 'l')
		return (ft_printf_wstring(ap, flags));
	str = va_arg(ap, char *);
	string_rules(flags, str);
	size = ft_printf_tmp(str, flags->precision, SET);
	flags->precision = (flags->precision > size) ? size : flags->precision;
	ft_printf_join(flags, NULL);
	return (0);
}
