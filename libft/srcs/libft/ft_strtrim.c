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

static int		test_trim(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_isspace(*str))
			return (1);
		str++;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	end;
	const char		*tmp;

	if (!test_trim((char *)s))
		return (ft_strdup(""));
	i = 0;
	end = ft_strlen(s);
	tmp = s;
	while (ft_isspace(s[i]))
		i++;
	while (*s)
		s++;
	while (ft_isspace(*--s))
		end--;
	return (ft_strsub(tmp, i, end - i));
}
