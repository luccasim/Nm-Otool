/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 23:58:26 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/23 16:10:05 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdlib.h>

void	ft_treedel(t_tree **a, void (*del)())
{
	if (!*a)
		return ;
	if ((*a)->left == NULL && (*a)->right == NULL)
	{
		del(&((*a)->content));
		free(*a);
		*a = NULL;
	}
}
