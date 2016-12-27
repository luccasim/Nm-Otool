/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 05:12:32 by luccasim          #+#    #+#             */
/*   Updated: 2015/10/14 16:39:20 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int		test_trim(char const *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (i);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;

	if (!s)
		return (0);
	start = test_trim(s);
	end = ft_strlen(s);
	while (end && ft_isspace(s[end - 1]))
		end--;
	return (ft_strsub(s, start, end - start));
}
