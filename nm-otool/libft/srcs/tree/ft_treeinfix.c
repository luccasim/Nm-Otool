/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeinfix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:48:52 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/23 16:05:14 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <tree.h>

static void		rec_treeinfix(t_tree *a, int (*aff)(void *), char *sep)
{
	if (!a)
		return ;
	rec_treeinfix(a->left, aff, sep);
	aff(a->content);
	if (sep)
		ft_putstr(sep);
	rec_treeinfix(a->right, aff, sep);
}

void			ft_treeinfix(t_tree *a, int (*aff)(void *), char *sep)
{
	rec_treeinfix(a, aff, sep);
	ft_putchar('\n');
}
