/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:41:15 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/07 15:52:04 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static void		norme(int c, char *tab)
{
	int	len;

	len = 0;
	tab[len++] = 0xFC | (c >> 30);
	tab[len++] = 0x80 | ((c >> 24) & 0x3F);
	tab[len++] = 0x80 | ((c >> 18) & 0x3F);
	tab[len++] = 0x80 | ((c >> 12) & 0x3F);
	tab[len++] = 0x80 | ((c >> 6) & 0x3F);
	tab[len++] = 0x80 | (c & 0x3F);
	tab[len] = 0;
}

static int		write_4byte_char(int c, char *tab)
{
	int	len;

	len = 0;
	if (c < 0x200000)
	{
		tab[len++] = 0xF0 | (c >> 18);
		tab[len++] = 0x80 | ((c >> 12) & 0x3F);
		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	else if (c < 0x4000000)
	{
		tab[len++] = 0xF8 | (c >> 24);
		tab[len++] = 0x80 | ((c >> 18) & 0x3F);
		tab[len++] = 0x80 | ((c >> 12) & 0x3F);
		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	else
		norme(c, tab);
	tab[len] = 0;
	return (ft_printf_buffer(tab, BUF_WRITE));
}

static int		write_2byte_char(int c, char *tab)
{
	int	len;

	len = 0;
	if (c < 0x80)
		tab[len++] = c;
	else if (c < 0x800)
	{
		tab[len++] = 0xC0 | (c >> 6);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	else if (c < 0x10000)
	{
		tab[len++] = 0xE0 | (c >> 12);
		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	tab[len] = 0;
	if (!tab[0])
		return (ft_printf_buffer(tab, BUF_CHAR));
	else
		return (ft_printf_buffer(tab, BUF_WRITE));
}

int				ft_printf_wchar(int c)
{
	char	tab[10];

	if (c < 0x200000)
		return (write_2byte_char(c, tab));
	else
		return (write_4byte_char(c, tab));
}
