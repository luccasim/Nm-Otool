/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 01:23:24 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:42:12 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

static int			write_color(char *color, char *style)
{
	char		*base;
	char		balise[16];
	int			i;
	int			split;

	base = "\033[";
	split = (color[0] && style[0]) ? 1 : 0;
	i = 0;
	while (!(*base == 0 && *color == 0 && *style == 0))
	{
		if (*base)
			balise[i] = *base++;
		else if (*color)
			balise[i] = *color++;
		else if (split && !(split = 0))
			balise[i] = ';';
		else
			balise[i] = *style++;
		i++;
	}
	balise[i] = 'm';
	balise[i + 1] = 0;
	ft_printf_buffer(balise, BUF_WRITE);
	return (1);
}

static int			check_color(char *tab, char *style)
{
	if (!*tab && *style)
		return (write_color(style, tab));
	else if (ft_printf_strequ(tab, "red"))
		return (write_color("31", style));
	else if (ft_printf_strequ(tab, "dark"))
		return (write_color("30", style));
	else if (ft_printf_strequ(tab, "white"))
		return (write_color("37", style));
	else if (ft_printf_strequ(tab, "green"))
		return (write_color("32", style));
	else if (ft_printf_strequ(tab, "yellow"))
		return (write_color("33", style));
	else if (ft_printf_strequ(tab, "blue"))
		return (write_color("34", style));
	else if (ft_printf_strequ(tab, "pink"))
		return (write_color("35", style));
	else if (ft_printf_strequ(tab, "cyan"))
		return (write_color("36", style));
	else if (ft_printf_strequ(tab, "eof"))
		return (write_color("0", style));
	return (0);
}

static int			set_tab(char *str, char *tab, int value)
{
	int	i;
	int	write;

	i = 0;
	write = 0;
	if (value == 0 && (str[0] >= 'a' && str[0] <= 'z'))
		write = 1;
	if (value == 1 && (str[0] >= '0' && str[0] <= '9'))
		write = 1;
	if (value == 2 && (str[0] == '%'))
		write = 1;
	if (!write)
		return (0);
	while (!(str[i] == ':' || str[i] == '}'))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = 0;
	if (str[i] == ':')
		i++;
	return (i);
}

static int			get_color(char *str, int size, int j, va_list ap)
{
	char	color[size + 1];
	char	style[size + 1];
	char	arg[size + 1];
	int		i;
	int		ret;

	if (j == 1)
		return (0);
	i = 0;
	color[0] = 0;
	style[0] = 0;
	arg[0] = 0;
	i += set_tab(str + i, color, 0);
	i += set_tab(str + i, style, 1);
	i += set_tab(str + i, arg, 2);
	ret = check_color(color, style);
	if (arg[0] && (color[0] || style[0]))
	{
		ft_printf_lexer(arg, ap);
		ret = check_color("e", "");
	}
	return (ret);
}

int					ft_printf_color(char *str, va_list ap)
{
	int		i;
	int		j;

	str++;
	i = 0;
	while (!(str[i] == '}' || str[i] == 0))
		i++;
	j = (str[i] == 0) ? 1 : 2;
	i = (get_color(str, i, j, ap)) ? i + j : 0;
	if (!i)
	{
		i = 1;
		ft_printf_buffer("{", BUF_CHAR);
	}
	return (i);
}
