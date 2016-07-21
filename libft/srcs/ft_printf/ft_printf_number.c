/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 06:45:50 by luccasim          #+#    #+#             */
/*   Updated: 2016/07/14 06:45:54 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

int		ft_printf_number(va_list ap)
{
	t_printf_flags	*flags;
	int				*ptr;

	flags = get_printf_flags(GET_FLAGS);
	ptr = va_arg(ap, int *);
	*ptr = ft_printf_buffer(NULL, 0);
	return (0);
}
