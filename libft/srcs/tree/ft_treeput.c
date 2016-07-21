/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 02:16:07 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/23 16:12:47 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree.h"

static void		rec_treeput(t_tree *a, int (*aff)(), char *sep)
{
	if (!a)
		return ;
	rec_treeput(a->left, aff, sep);
	aff(a->content);
	if (sep)
		ft_putstr(sep);
	rec_treeput(a->right, aff, sep);
}

void			ft_treeput(t_tree *a, int (*aff)(), char *sep)
{
	rec_treeput(a, aff, sep);
	ft_putchar('\n');
}
