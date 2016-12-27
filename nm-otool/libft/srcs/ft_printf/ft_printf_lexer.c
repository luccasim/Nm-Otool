/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:43:32 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:50:36 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static	int	set_flags(char *str, va_list ap, t_printf_flags *flags)
{
	int	end;
	int	i;
	int	j;

	end = 1;
	i = 1;
	while (end)
	{
		j = 0;
		if (j += set_printf_flags(str + i, flags))
			i += j;
		else if (j += set_printf_width(str + i, ap, flags))
			i += j;
		else if (j += set_printf_precision(str + i, ap, flags))
			i += j;
		else if (j += set_printf_length(str + i, flags))
			i += j;
		else
			end = 0;
	}
	i += set_printf_conversion(str + i, flags);
	return (i);
}

int			ft_printf_lexer(char *str, va_list ap)
{
	int				i;
	t_printf_flags	*flags;

	flags = get_printf_flags(RESET_FLAGS);
	i = set_flags(str, ap, flags);
	ft_printf_conversion(ap, flags);
	get_printf_flags(RESET_FLAGS);
	return (i);
}
