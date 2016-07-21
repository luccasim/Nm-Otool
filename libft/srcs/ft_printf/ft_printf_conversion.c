/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:50:52 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:50:57 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

t_func	g_tab[] =
{
	{ft_printf_percentage, '%'},
	{ft_printf_integer, 'd'},
	{ft_printf_integer, 'i'},
	{ft_printf_uinteger, 'x'},
	{ft_printf_uinteger, 'X'},
	{ft_printf_uinteger, 'o'},
	{ft_printf_uinteger, 'u'},
	{ft_printf_long, 'D'},
	{ft_printf_long, 'U'},
	{ft_printf_long, 'O'},
	{ft_printf_long, 'C'},
	{ft_printf_long, 'S'},
	{ft_printf_long, 'F'},
	{ft_printf_number, 'n'},
	{ft_printf_date, 'k'},
	{ft_printf_string, 's'},
	{ft_printf_char, 'c'},
	{ft_printf_address, 'p'},
	{ft_printf_float, 'f'},
	{ft_printf_bin, 'b'},
	{NULL, -1}
};

static int	printf_convertion(char c, va_list ap)
{
	int	i;

	i = 0;
	while (g_tab[i].key != -1)
	{
		if (g_tab[i].key == c)
			return (g_tab[i].ptrfunc(ap));
		i++;
	}
	return (1);
}

static int	invalid_conversion(t_printf_flags *flags)
{
	char	tab[2];
	char	marg;

	if (!flags->conversion)
		return (0);
	tab[0] = flags->conversion;
	tab[1] = 0;
	marg = (flags->FLAGS_ZERO) ? '0' : ' ';
	if (!flags->FLAGS_DASH)
		ft_printf_margin(marg, flags->width - 1);
	ft_printf_buffer(tab, BUF_CHAR);
	if (flags->FLAGS_DASH)
		ft_printf_margin(' ', flags->width - 1);
	return (0);
}

int			ft_printf_conversion(va_list ap, t_printf_flags *flags)
{
	if (printf_convertion(flags->conversion, ap))
		return (invalid_conversion(flags));
	return (0);
}
