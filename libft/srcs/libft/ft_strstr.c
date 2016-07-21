/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 00:53:16 by luccasim          #+#    #+#             */
/*   Updated: 2015/10/14 16:38:16 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *s2)
{
	if (*s2 == 0)
		return ((char *)s);
	while ((s = ft_memchr(s, s2[0], ft_strlen(s))))
	{
		if (ft_memcmp(s, s2, ft_strlen(s2)) == 0)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
