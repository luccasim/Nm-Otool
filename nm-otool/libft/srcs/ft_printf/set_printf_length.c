/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_printf_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:10:53 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/07 16:11:13 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static int	is_long(char c)
{
	if (c == 'h' || c == 'H' || c == '0')
		return (0);
	else
		return (1);
}

static int	keep_length(char c, t_printf_flags *flags)
{
	if (is_long(flags->length) && (c == 'h' || c == 'H'))
		return (flags->length);
	else
		return (c);
}

static int	set_length(char c, t_printf_flags *flags)
{
	flags->length = keep_length(c, flags);
	flags->setting = 1;
	if (c == 'L' || c == 'H')
		return (2);
	else
		return (1);
}

int			set_printf_length(char *arg, t_printf_flags *flags)
{
	if (arg[0] == 'l' || arg[0] == 'h')
	{
		if (arg[1] == 'l' && arg[0] == 'l')
			return (set_length('L', flags));
		if (arg[1] == 'h' && arg[0] == 'h')
			return (set_length('H', flags));
		return (set_length(arg[0], flags));
	}
	else if (arg[0] == 'j' || arg[0] == 'z')
		return (set_length(arg[0], flags));
	else
		return (0);
}
