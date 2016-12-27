/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 19:25:37 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/17 14:36:16 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	unsigned char		t1;
	unsigned char		t2;

	t1 = *s1;
	t2 = *s2;
	if (!t1 && !t2)
		return (0);
	if (t1 != t2)
		return (t1 - t2);
	return (ft_strcmp(++s1, ++s2));
}
