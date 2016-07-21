/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putdouble.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:33:11 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:49:44 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

int	ft_printf_putdouble(double f, int size)
{
	unsigned long long	nb;
	int					i;
	char				tab[size + 1];

	f = (f < 0) ? -f : f;
	nb = f;
	if (nb)
		ft_printf_putnbr(nb, 10, 0);
	else
		ft_printf_tmp("0", -1, SET);
	if (size)
		ft_printf_tmp(".", -1, SET);
	i = 0;
	tab[size] = 0;
	while (i < size)
	{
		f *= 10;
		nb = f;
		tab[i] = (nb % 10) + '0';
		i++;
	}
	ft_printf_tmp(tab, -1, SET);
	return (0);
}
