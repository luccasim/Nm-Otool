/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:55:11 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:55:14 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

int		ft_printf_long(va_list ap)
{
	t_printf_flags		*flags;

	flags = get_printf_flags(GET_FLAGS);
	flags->length = 'l';
	flags->setting = 1;
	flags->conversion = flags->conversion - 'A' + 'a';
	return (ft_printf_conversion(ap, flags));
}
