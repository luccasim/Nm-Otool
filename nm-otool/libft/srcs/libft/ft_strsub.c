/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 05:02:23 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/17 14:41:39 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (!s || (int)len < 0)
		return (NULL);
	new = ft_strnew(len);
	if (!new)
		return (new);
	i = 0;
	while (len)
	{
		new[i] = s[i + start];
		i++;
		len--;
	}
	return (new);
}
