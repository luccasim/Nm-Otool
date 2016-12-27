/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:55:27 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:59:57 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

int	ft_fprintf(int fd, char *str, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, str);
	ft_printf_fd(fd, SET);
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
	ret = ft_printf_buffer(str, BUF_READ);
	ft_printf_fd(1, SET);
	return (ret);
}
