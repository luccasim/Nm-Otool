/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:42:30 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 01:59:58 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		rec_putnbr(int nb, int *k)
{
	if (nb >= 10)
		rec_putnbr(nb / 10, k);
	*k += ft_putchar((nb % 10) + '0');
}

int				ft_putnbr(int nb)
{
	int	k;

	k = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		nb = -nb;
		k += ft_putchar('-');
	}
	rec_putnbr(nb, &k);
	return (k);
}
