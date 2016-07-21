/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 15:10:47 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/17 16:47:19 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **lst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	if (!lst)
		return ;
	if (!*lst)
		return ;
	tmp = *lst;
	next = tmp->next;
	del(tmp->content, tmp->content_size);
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
	*lst = next;
}
