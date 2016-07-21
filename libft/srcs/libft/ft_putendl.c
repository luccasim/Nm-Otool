/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:49:52 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/17 14:32:36 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl(const char *str)
{
	int		ret;

	if (!str)
		ret = ft_putstr_fd("(NULL)", 2);
	else
		ret = ft_putstr(str);
	ft_putchar('\n');
	return (ret + 1);
}
