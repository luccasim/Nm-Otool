/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 15:45:53 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/17 16:13:06 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

static void		rec_lstmap(t_list *lst, t_list *(*f)(t_list *elem), t_list **n)
{
	if (!lst)
		return ;
	rec_lstmap(lst->next, f, n);
	ft_lstadd(n, f(lst));
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	new = NULL;
	if (!lst)
		return (NULL);
	rec_lstmap(lst, f, &new);
	return (new);
}
