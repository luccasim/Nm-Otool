/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:22:12 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 01:59:29 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		overlap_static(char *d, const char *s, size_t n)
{
	char		tmp[n];

	ft_bzero(tmp, n);
	ft_memcpy(tmp, s, n);
	ft_memcpy(d, tmp, n);
}

static void		overlap_dynamique(char *d, const char *s, size_t n, char *tmp)
{
	ft_bzero(tmp, n);
	ft_memcpy(tmp, s, n);
	ft_memcpy(d, tmp, n);
}

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	char			*dst;
	const char		*src;
	char			*tmp;

	dst = s1;
	src = s2;
	tmp = (char *)malloc(sizeof(dst) * n);
	if (!tmp)
		overlap_static(s1, s2, n);
	else
		overlap_dynamique(s1, s2, n, tmp);
	free(tmp);
	return (s1);
}
