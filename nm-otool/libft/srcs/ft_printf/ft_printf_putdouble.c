/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putdouble.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:33:11 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 16:59:05 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static void			write_margin(int nb)
{
	char	tab[nb + 1];
	int		i;

	i = 0;
	if (nb > 0)
	{
		while (i < nb)
		{
			tab[i] = '0';
			i++;
		}
		tab[i] = 0;
		ft_printf_tmp(tab, -1, SET);
	}
}

static int			write_decimal(long double f, int size)
{
	int					i;
	int					k;
	uint64_t			nb;

	i = 0;
	k = 0;
	nb = 0;
	while (i < size)
	{
		f *= 10;
		i++;
		nb = f;
		if (!nb)
			k++;
	}
	return (k);
}

static uint64_t		myround(long double f)
{
	long double		dec;
	uint64_t		nb;

	nb = f;
	dec = f - nb;
	return ((dec < 0.5) ? nb : nb + 1);
}

int					ft_printf_putdouble(double f, int size)
{
	unsigned long long	nb;
	long double			r;

	f = (f < 0) ? -f : f;
	nb = f;
	if (nb)
		ft_printf_putnbr(nb, 10, 0);
	else
		ft_printf_tmp("0", -1, SET);
	if (size)
		ft_printf_tmp(".", -1, SET);
	r = f - nb;
	nb = myround(r * ft_printf_pow(10, size));
	write_margin(write_decimal(r, size));
	ft_printf_putnbr(nb, 10, 0);
	return (0);
}
