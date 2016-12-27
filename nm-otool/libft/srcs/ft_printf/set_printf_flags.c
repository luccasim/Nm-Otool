/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_printf_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:03:10 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/07 17:51:49 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static int		set_flags(int tab, t_printf_flags *flags)
{
	flags->flags[tab] = 1;
	flags->setting = 1;
	return (1);
}

static int		is_flags(int c, t_printf_flags *flags)
{
	if (c == '#')
		return (set_flags(0, flags));
	if (c == '-')
		return (set_flags(1, flags));
	if (c == '+')
		return (set_flags(2, flags));
	if (c == ' ')
		return (set_flags(3, flags));
	if (c == '0')
		return (set_flags(4, flags));
	return (0);
}

int				set_printf_flags(char *arg, t_printf_flags *flags)
{
	int	i;

	i = 0;
	while (is_flags(arg[i], flags))
		i++;
	return (i);
}
