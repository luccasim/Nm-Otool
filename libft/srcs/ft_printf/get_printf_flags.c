/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printf_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:58:05 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/07 16:00:19 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static void		init(t_printf_flags *sglt)
{
	int	i;

	i = 0;
	while (i < 5)
		sglt->flags[i++] = 0;
	sglt->width = 0;
	sglt->precision = -1;
	sglt->length = '0';
	sglt->conversion = 0;
	sglt->setting = 0;
}

t_printf_flags	*get_printf_flags(int action)
{
	static t_printf_flags	sglt;

	if (action == RESET_FLAGS)
		init(&sglt);
	return (&sglt);
}
