/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:53:38 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:59:18 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static unsigned long long	cplt2(long long a)
{
	unsigned long long ret;

	if (a < 0)
	{
		ret = 0xFFFFFFFFFFFFFFFF - a;
		ret--;
	}
	else
		ret = a;
	return (ret);
}

static	void				bin(unsigned long long nb, int size)
{
	char		tab[size + 1];
	int			i;

	i = 0;
	tab[size] = 0;
	while (i < size)
	{
		tab[(size - 1) - i] = (nb % 2) + '0';
		nb /= 2;
		i++;
	}
	ft_printf_tmp(tab, -1, SET);
}

int							ft_printf_bin(va_list ap)
{
	t_printf_flags	*flags;
	int				size;
	long long		nb;

	flags = get_printf_flags(GET_FLAGS);
	size = 16;
	nb = va_arg(ap, long long);
	if (flags->setting)
		size = (flags->precision < 0) ? 16 : flags->precision;
	size = (size > 64) ? 64 : size;
	bin(cplt2(nb), size);
	ft_printf_join(flags, NULL);
	return (0);
}
