/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:53:58 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 16:54:00 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static char	section_symbol(int value, t_list *sl)
{
	t_list		*tmp;
	t_section	*section;
	char		c;

	tmp = sl;
	c = 's';
	while (tmp)
	{
		section = tmp->content;
		if (section)
		{
			if (value == section->nb)
			{
				if (ft_strequ(section->name, SECT_TEXT))
					c = 't';
				if (ft_strequ(section->name, SECT_DATA))
					c = 'd';
				if (ft_strequ(section->name, SECT_BSS))
					c = 'b';
			}
		}
		tmp = tmp->next;
	}
	return (c);
}

char		symbol_type(char value, char sect, char type, t_list *sl)
{
	char c;

	c = '?';
	if (type & N_STAB)
		c = '-';
	else if ((type & N_TYPE) == N_UNDF)
	{
		c = 'u';
		if (value != 0)
			c = 'c';
	}
	else if ((type & N_TYPE) == N_PBUD)
		c = 'u';
	else if ((type & N_TYPE) == N_ABS)
		c = 'a';
	else if ((type & N_TYPE) == N_SECT)
		c = section_symbol(sect, sl);
	else if ((type & N_TYPE) == N_INDR)
		c = 'i';
	if ((type & N_EXT) && c != '?')
		c = ft_toupper(c);
	return (c);
}
