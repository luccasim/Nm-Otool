/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 23:03:41 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/23 18:26:34 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	const char	*src;
	char		*dst;

	dst = s1;
	src = s2;
	while (n)
	{
		if (*src != 0)
			*dst++ = *src++;
		else
			*dst++ = 0;
		n--;
	}
	return (s1);
}
