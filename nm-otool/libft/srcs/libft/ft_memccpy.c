/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:36:25 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/16 16:19:57 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned char const		*s;
	unsigned char			*d;

	if (n)
	{
		s = src;
		d = dst;
		while (n--)
		{
			if ((*d++ = *s++) == (unsigned char)c)
				return (d);
		}
	}
	return (NULL);
}
