/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:53:36 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/17 14:33:03 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_fd(const char *str, int fd)
{
	int		ret;

	ret = ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
	return (ret + 1);
}
