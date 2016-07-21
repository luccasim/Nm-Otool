/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:37:51 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/16 00:10:40 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <tree.h>

t_tree	*ft_treenew(void *content)
{
	t_tree	*new;

	new = (t_tree *)malloc(sizeof(t_tree));
	if (new)
	{
		new->content = content;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}
