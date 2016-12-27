/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:05:45 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:07:35 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strstrlen(char **split)
{
	size_t	size;

	size = 0;
	while (*split)
	{
		size++;
		split++;
	}
	return (size);
}
