/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:04:55 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:55:45 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static void			write_address(t_printf_flags *flags)
{
	char	*sign;

	sign = "0x";
	ft_printf_join(flags, sign);
}

int					ft_printf_address(va_list ap)
{
	void			*addr;
	t_printf_flags	*flags;

	flags = get_printf_flags(GET_FLAGS);
	addr = va_arg(ap, void *);
	ft_printf_putnbr((unsigned long long)addr, 16, 'x');
	write_address(flags);
	return (0);
}
