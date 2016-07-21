/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:40:37 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/17 14:35:01 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putstr_fd(const char *str, int fd)
{
	if (str)
		return (write(fd, str, ft_strlen(str)));
	else
		return (write(fd, "(null)", 6));
}
