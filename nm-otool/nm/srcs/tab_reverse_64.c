/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:13:03 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 17:13:06 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_tab_reverse_64(int64_t *tab, uint64_t size)
{
	uint64_t	i;
	uint64_t	tmp;
	uint64_t	j;

	if (!tab)
		return ;
	i = 0;
	while (i < size / 2)
	{
		j = size - 1 - i;
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
	}
}
