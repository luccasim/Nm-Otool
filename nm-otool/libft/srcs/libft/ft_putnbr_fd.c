/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:47:03 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 02:01:53 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		rec_putnbr(int nb, int *k, int fd)
{
	if (nb >= 10)
		rec_putnbr(nb / 10, k, fd);
	*k += ft_putchar_fd((nb % 10) + '0', fd);
}

int				ft_putnbr_fd(int nb, int fd)
{
	int	k;

	k = 0;
	if (nb == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (nb < 0)
	{
		nb = -nb;
		k += ft_putchar_fd('-', fd);
	}
	rec_putnbr(nb, &k, fd);
	return (k);
}
