/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:53:55 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 02:35:01 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + ((*s1) ? 1 : 0);
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return (ft_memcpy(new, s1, ft_strlen(s1)));
}
