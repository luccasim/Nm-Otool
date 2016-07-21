/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_margin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:26:42 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 03:20:59 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

void	ft_printf_margin(char c, int a)
{
	int		i;

	if (a > 0)
	{
		i = 0;
		while (i++ < a)
			ft_printf_buffer(&c, BUF_CHAR);
	}
}
