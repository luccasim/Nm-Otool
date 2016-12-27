/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 06:45:31 by luccasim          #+#    #+#             */
/*   Updated: 2016/07/14 06:45:36 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"
#include <time.h>

static void	format_date(int flags, struct tm *date, char *format)
{
	char	str[128];
	char	*ptr;

	ptr = str;
	if (flags == 'h')
		strftime(ptr, 128, "%X", date);
	else if (flags == 'H')
		strftime(ptr, 128, "%s", date);
	else if (flags == 'l')
		strftime(ptr, 128, "%A %B %d %Y %r", date);
	else if (flags == 'L')
		strftime(ptr, 128, "%A %B %d %Y %X", date);
	else if (flags == 'j')
		strftime(ptr, 128, "%x", date);
	else if (flags == 'z' && format)
		strftime(ptr, 128, format, date);
	else
		strftime(ptr, 128, "%c", date);
	ft_printf_tmp(ptr, -1, SET);
}

int			ft_printf_date(va_list ap)
{
	time_t			secondes;
	struct tm		*time;
	t_printf_flags	*flags;
	char			*format;

	flags = get_printf_flags(GET_FLAGS);
	secondes = va_arg(ap, time_t);
	time = localtime(&secondes);
	format = NULL;
	if (flags->length == 'z')
		format = va_arg(ap, char*);
	format_date(flags->length, time, format);
	ft_printf_join(flags, NULL);
	return (0);
}
