/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:28:33 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/07 15:29:18 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

int	ft_printf_percentage(va_list ap)
{
	t_printf_flags	*flags;
	char			margin;

	(void)ap;
	flags = get_printf_flags(GET_FLAGS);
	margin = (flags->FLAGS_ZERO) ? '0' : ' ';
	if (!flags->FLAGS_DASH)
		ft_printf_margin(margin, flags->width - 1);
	ft_printf_buffer("%", BUF_WRITE);
	if (flags->FLAGS_DASH)
		ft_printf_margin(' ', flags->width - 1);
	return (0);
}
