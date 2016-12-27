/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double_scient.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:33:11 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:49:44 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

int	ft_printf_double_scient(double f, int size)
{
	unsigned long long	nb;
	long double			r;
	int					i;

	f = (f < 0) ? -f : f;
	nb = f;
	if (nb)
		ft_printf_putnbr(nb, 10, 0);
	else
		ft_printf_tmp("0", -1, SET);
	if (size)
		ft_printf_tmp("P", -1, SET);
	i = 0;
	r = f - nb;
	nb = (r * ft_printf_pow(10, size));
	ft_printf_putnbr(nb, 10, 0);
	return (0);
}
