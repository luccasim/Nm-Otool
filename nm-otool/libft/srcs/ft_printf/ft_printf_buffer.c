/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:10:43 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 03:20:44 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_struct.h"

static void	read_buffer(char *buffer, int *i)
{
	int	size;
	int	fd;

	fd = ft_printf_fd(0, GET);
	size = *i;
	write(fd, buffer, size);
	*i = 0;
}

static int	write_str(char *buf, int *size, char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	j = *size;
	while (str[i])
	{
		if (j == BUF_SIZE)
			read_buffer(buf, &j);
		buf[j++] = str[i++];
	}
	buf[j] = 0;
	*size = j;
	return (i);
}

static int	write_char(char *buf, int *size, int c)
{
	int	j;

	j = *size;
	if (j == BUF_SIZE)
		read_buffer(buf, &j);
	buf[j++] = c;
	*size = j;
	return (1);
}

int			ft_printf_buffer(char *str, int act)
{
	static char		buf[BUF_SIZE + 1];
	static int		size = 0;
	static int		total = 0;
	int				i;

	i = total;
	if (act == BUF_CHAR)
		total += write_char(buf, &size, *str);
	else if (act == BUF_WRITE)
		total += write_str(buf, &size, str);
	else if (act == BUF_READ)
	{
		read_buffer(buf, &size);
		i = total;
		total = 0;
	}
	return (i);
}
