/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:39:58 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/18 22:43:33 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "list.h"

typedef struct		s_tree
{
	void			*content;
	struct s_tree	*right;
	struct s_tree	*left;
}					t_tree;

t_tree				*ft_treenew(void *content);
void				ft_treeadd(t_tree **a, void *c, int(*sort)());
void				ft_treedel(t_tree **a, void(*del)());
void				ft_treedestroy(t_tree **a, void(*del)());
void				ft_treeinfix(t_tree *a, int(*aff)(), char *sep);
void				ft_treesufix(t_tree *a, int(*aff)(), char *sep);
void				ft_treeprefix(t_tree *a, int(*aff)(), char *sep);
void				ft_treeput(t_tree *a, int(*aff)(), char *sep);
void				ft_treeputrev(t_tree *a, int(*aff)(), char *sep);
t_tree				*ft_listtotree(t_list *list, int(*sort)());
int					ft_treesize(t_tree *a);

#endif
