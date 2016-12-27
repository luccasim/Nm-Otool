/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:44:06 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:57:44 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static int	sign_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	marg_conversion(int c)
{
	if (c == 's')
		return (' ');
	else
		return ('0');
}

int			ft_printf_join(t_printf_flags *flags, char *str)
{
	int		size;
	int		prec;
	char	marg;

	size = ft_printf_tmp(NULL, 0, GET);
	prec = (size > flags->precision) ? size : flags->precision;
	marg = (flags->FLAGS_ZERO) ? '0' : ' ';
	flags->width -= sign_len(str);
	if (!flags->FLAGS_DASH)
	{
		if (marg == '0')
			ft_printf_buffer(str, BUF_WRITE);
		ft_printf_margin(marg, flags->width - prec);
	}
	if (marg == ' ')
		ft_printf_buffer(str, BUF_WRITE);
	if (prec > size && size)
		ft_printf_margin(marg_conversion(flags->conversion), prec - size);
	ft_printf_tmp(NULL, 0, SEND);
	if (flags->FLAGS_DASH)
		ft_printf_margin(' ', flags->width - prec);
	return (0);
}
