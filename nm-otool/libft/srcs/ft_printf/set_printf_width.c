/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_printf_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:11:54 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 04:51:21 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

int	set_printf_width(char *arg, va_list ap, t_printf_flags *flags)
{
	char		*tmp;
	int			nbr;

	tmp = arg;
	if (*tmp == '*' || (*tmp >= '0' && *tmp <= '9'))
	{
		if (*tmp == '*' && arg++)
		{
			nbr = va_arg(ap, int);
			if (nbr < 0)
			{
				nbr = -nbr;
				flags->FLAGS_DASH = 1;
			}
			flags->width = nbr;
		}
		else
			flags->width = ft_printf_atoi(&arg);
		if (flags->width)
			flags->setting = 1;
	}
	return (arg - tmp);
}
