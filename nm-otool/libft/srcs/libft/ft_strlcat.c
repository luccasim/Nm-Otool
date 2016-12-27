/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 23:16:10 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/17 14:38:31 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		size_dst;
	char		*d;
	const char	*s;
	size_t		n;

	d = dst;
	s = src;
	n = size;
	while (*d && n--)
		d++;
	size_dst = d - dst;
	n = size - size_dst;
	if (!n)
		return (size_dst + ft_strlen(src));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = 0;
	return (size_dst + ft_strlen(src));
}
