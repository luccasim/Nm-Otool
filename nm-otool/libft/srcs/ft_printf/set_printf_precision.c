/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_printf_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:11:36 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 05:03:20 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

int	set_printf_precision(char *arg, va_list ap, t_printf_flags *flags)
{
	char	*tmp;
	int		nb;

	tmp = arg;
	if (*arg == '.')
	{
		arg++;
		if (*arg == '*' && arg++)
		{
			nb = va_arg(ap, int);
			flags->setting = (nb < 0) ? flags->setting : 1;
			nb = (nb < 0) ? flags->precision : nb;
			flags->precision = nb;
		}
		else
		{
			flags->precision = ft_printf_atoi(&arg);
			flags->setting = 1;
		}
	}
	return (arg - tmp);
}
