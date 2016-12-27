/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeputrev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 02:20:01 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/23 16:28:50 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree.h"

static void		rec_treeputrev(t_tree *a, int (*aff)(), char *sep)
{
	if (!a)
		return ;
	rec_treeputrev(a->right, aff, sep);
	aff(a->content);
	if (sep)
		ft_putstr(sep);
	rec_treeputrev(a->left, aff, sep);
}

void			ft_treeputrev(t_tree *a, int (*aff)(), char *sep)
{
	rec_treeputrev(a, aff, sep);
}
