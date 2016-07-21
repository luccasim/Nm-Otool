/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_printf_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:02:50 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/07 16:08:48 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

int	set_printf_conversion(char *arg, t_printf_flags *flags)
{
	if (!*arg)
		return (0);
	flags->conversion = *arg;
	return (1);
}
