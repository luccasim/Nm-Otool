/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:53:00 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 16:53:05 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <stdlib.h>

void	section_del(void *addr, size_t content_size)
{
	t_section	*sect;

	sect = (t_section *)addr;
	if (content_size)
	{
		sect->name = NULL;
		sect->nb = 0;
		free(sect);
	}
}
