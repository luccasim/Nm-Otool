/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 15:23:55 by luccasim          #+#    #+#             */
/*   Updated: 2015/03/17 16:15:51 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
	if (!lst)
		return ;
	if (!*lst)
		return ;
	ft_lstdel(&(*lst)->next, del);
	ft_lstdelone(lst, del);
}
