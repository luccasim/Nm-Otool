/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:40:59 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/23 18:38:52 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *src, const void *dst, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = src;
	s2 = dst;
	if (!n)
		return (0);
	else if (*s1 != *s2)
		return (*s1 - *s2);
	return (ft_memcmp(++src, ++dst, --n));
}
