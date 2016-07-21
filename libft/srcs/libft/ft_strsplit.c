/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 21:01:17 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 02:00:52 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t		count_tab(char const *s, char c)
{
	size_t	k;

	k = 1;
	while (*s)
	{
		if (*s == c)
		{
			k++;
			while (*s == c)
				s++;
		}
		s++;
	}
	return (k);
}

static	size_t		count_size(char const *s, char c)
{
	size_t	k;

	k = 0;
	while (*s && *s != c)
	{
		k++;
		s++;
	}
	return (k);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	size;
	char	**tab;
	int		j;

	if (!s)
		return (NULL);
	size = count_tab(s, c);
	tab = (char **)malloc(sizeof(char *) * size + 1);
	if (tab)
	{
		j = 0;
		while (*s)
		{
			if (*s != c)
			{
				size = count_size(s, c);
				tab[j++] = ft_strsub(s, 0, size);
				s = s - 1 + size;
			}
			s++;
		}
		tab[j] = NULL;
		return (tab);
	}
	return (NULL);
}
