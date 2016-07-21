/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:27:40 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/07 15:28:15 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf_nbrlen(long long nbr, int base)
{
	int		size;

	if (nbr == 0)
		return (1);
	size = 0;
	while (nbr)
	{
		nbr /= base;
		size++;
	}
	return (size);
}
