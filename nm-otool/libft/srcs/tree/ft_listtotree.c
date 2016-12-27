/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listtotree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 02:51:25 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/23 16:09:00 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree		*ft_listtotree(t_list *list, int (*sort)())
{
	t_tree		*new;

	new = 0;
	if (!list)
		return (new);
	while (list)
	{
		ft_treeadd(&new, list->content, sort);
		list = list->next;
	}
	return (new);
}
