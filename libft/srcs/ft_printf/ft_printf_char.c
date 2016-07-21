/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:12:43 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/07 15:14:49 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static int	write_char(va_list ap, t_printf_flags *flags)
{
	int			size;
	char		tab[2];
	char		marg;
	int			wch;

	wch = va_arg(ap, int);
	tab[1] = 0;
	marg = (flags->FLAGS_ZERO) ? '0' : ' ';
	size = flags->width - 1;
	if (!flags->FLAGS_DASH)
		ft_printf_margin(marg, size);
	if (flags->length == 'l')
		ft_printf_wchar(wch);
	else
	{
		tab[0] = wch;
		ft_printf_buffer(tab, BUF_CHAR);
	}
	if (flags->FLAGS_DASH)
		ft_printf_margin(' ', size);
	return (0);
}

int			ft_printf_char(va_list ap)
{
	t_printf_flags	*flags;
	char			tab[2];

	tab[1] = 0;
	flags = get_printf_flags(GET_FLAGS);
	if (!flags->setting)
	{
		tab[0] = va_arg(ap, int);
		ft_printf_buffer(tab, BUF_CHAR);
	}
	else
		write_char(ap, flags);
	return (0);
}
