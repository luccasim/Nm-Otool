/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:32:45 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:51:41 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static int		write_tmp(char *buf, char *str, int size, int s)
{
	int	i;
	int	j;

	if (!str)
		str = "(null)";
	i = 0;
	j = s;
	while (!(str[i] == 0 || size == 0))
	{
		buf[j + i] = str[i];
		i++;
		size--;
	}
	buf[j + i] = 0;
	return (i);
}

int				ft_printf_tmp(char *str, int s, int act)
{
	static char	tmp[BUF_SIZE + 1];
	static int	size = 0;

	if (act == SET)
		return (size += write_tmp(tmp, str, s, size));
	else if (act == GET)
		return (size);
	else if (act == SEND)
		ft_printf_buffer(tmp, BUF_WRITE);
	size = 0;
	tmp[0] = 0;
	return (size);
}
