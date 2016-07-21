/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:39:25 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:43:09 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_printf_pow(int base, int pow)
{
	double	ret;
	double	fbase;
	int		i;

	ret = 1.0;
	i = 0;
	fbase = (double)(ret / base);
	while (i != pow)
	{
		ret *= (pow >= 0) ? base : fbase;
		i += (pow >= 0) ? 1 : -1;
	}
	return (ret);
}
