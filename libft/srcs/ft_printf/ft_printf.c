/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:00:01 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/29 16:02:23 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf_struct.h"

int	ft_printf(char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			str += ft_printf_lexer(str, ap);
		else if (*str == '{')
			str += ft_printf_color(str, ap);
		else
			ft_printf_buffer(str++, BUF_CHAR);
	}
	va_end(ap);
	return (ft_printf_buffer(str, BUF_READ));
}
