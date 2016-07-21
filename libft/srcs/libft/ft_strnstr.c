/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 01:07:10 by luccasim          #+#    #+#             */
/*   Updated: 2015/10/14 16:36:26 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_cmp(char *s1, char *s2, int mem)
{
	while (mem >= 0)
	{
		if (*s2 == 0)
			return (1);
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		mem -= 1;
	}
	return (0);
}

char		*ft_strnstr(const char *s, const char *s2, size_t n)
{
	if (*s2 == 0)
		return ((char *)s);
	while (n)
	{
		if (*s == *s2)
		{
			if (my_cmp((char *)s, (char *)s2, (int)n) == 1)
				return ((char*)s);
		}
		n--;
		if (*s == 0)
			return (NULL);
		s++;
	}
	return (NULL);
}
