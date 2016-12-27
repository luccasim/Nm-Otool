/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:32:25 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:42:36 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static int	get_number(int nbr, int c)
{
	if (nbr <= 9)
		return (nbr + '0');
	else if (c == 'X')
		return (nbr + 'A' - 10);
	else
		return (nbr + 'a' - 10);
}

static int	trivial(unsigned long long nbr)
{
	t_printf_flags	*flags;

	flags = get_printf_flags(GET_FLAGS);
	if (flags->precision == 0)
	{
		if (flags->FLAGS_HASH && flags->conversion == 'o')
			return (ft_printf_tmp("0", -1, SET));
		else
			return (nbr);
	}
	else
		return (ft_printf_tmp("0", -1, SET));
}

int			ft_printf_putnbr(unsigned long long nbr, int base, int c)
{
	char	tab[NBR_SIZE + 1];
	int		size;

	tab[NBR_SIZE] = 0;
	size = NBR_SIZE - 1;
	if (!nbr)
		return (trivial(nbr));
	while (nbr)
	{
		tab[size--] = get_number(nbr % base, c);
		nbr /= base;
		if (nbr && nbr < (unsigned int)base)
		{
			tab[size--] = get_number(nbr, c);
			nbr = 0;
		}
	}
	ft_printf_tmp(tab + size + 1, -1, SET);
	return (size);
}
