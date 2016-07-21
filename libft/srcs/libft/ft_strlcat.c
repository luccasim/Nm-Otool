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
	int		k;

	k = 0;
	while (*dst)
	{
		dst++;
		k++;
	}
	if ((int)size < k)
		return (size + ft_strlen(src));
	ft_memcpy(dst, src, (int)size - k - 1);
	return (k + ft_strlen(src));
}
