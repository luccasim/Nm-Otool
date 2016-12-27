/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:43:44 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/23 16:10:50 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tree.h"

void		ft_treeadd(t_tree **a, void *content, int (*sort)())
{
	if (*a == NULL)
		*a = ft_treenew(content);
	else if (sort(content, (*a)->content) < 0)
		ft_treeadd(&((*a)->left), content, sort);
	else
		ft_treeadd(&((*a)->right), content, sort);
}
