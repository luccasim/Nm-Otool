/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:53:54 by luccasim          #+#    #+#             */
/*   Updated: 2016/04/12 17:53:58 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_struct.h"

int	ft_printf_fd(int fd, int act)
{
	static int	ret = 1;

	if (act == SET)
		ret = fd;
	return (ret);
}
