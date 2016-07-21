/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 03:07:20 by luccasim          #+#    #+#             */
/*   Updated: 2015/10/14 16:29:27 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

static int		overflow(long test)
{
	if (test <= 2147483647 || test >= -2147483648)
		return (test);
	return (0);
}

int				ft_atoi(const char *str)
{
	long	sum;
	int		sign;

	sum = 0;
	sign = 1;
	while (ft_isspace(*str) || *str == '-' || *str == '+')
	{
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				sign = -sign;
			str++;
			break ;
		}
		str++;
	}
	while (ft_isdigit(*str))
	{
		sum = (10 * sum) + *str - 48;
		str++;
	}
	return (overflow(sum * sign));
}
