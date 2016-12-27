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
	size_t		i;
	size_t		size;
	char		*new;

	size = ft_strlen(s1);
	new = (char *)malloc(sizeof(char) * size + 1);
	i = 0;
	while (i < size)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
