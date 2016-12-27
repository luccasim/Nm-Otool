/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 04:23:22 by luccasim          #+#    #+#             */
/*   Updated: 2015/10/14 16:32:59 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t n)
{
	char	*new;

	new = (char *)ft_memalloc(sizeof(char) * n + 1);
	if (new)
		ft_bzero(new, n + 1);
	return (new);
}
