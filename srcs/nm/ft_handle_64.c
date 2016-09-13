/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 17:00:31 by luccasim          #+#    #+#             */
/*   Updated: 2016/09/12 17:00:37 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	printf_output(struct symtab_command *sym, void *header)
{
	struct nlist_64	*list;
	char			*stringtab;
	uint32_t		i;

	list = header + sym->symoff;
	stringtab = header + sym->stroff;
	i = 0;
	while (i < sym->nsyms)
	{
		ft_printf("{w:1:%s}\n",stringtab + list[i].n_un.n_strx);
		i++;
	}
	ft_printf(WORD ENDL, ft_options_sglt());
}

void		ft_handle_64(struct mach_header_64 *header)
{
	uint32_t 				ncmds;
	struct load_command		*lc;
	uint32_t				cmd;
	uint32_t				i;

	ncmds = header->ncmds;
	lc = (struct load_command*)(header + 1);
	i = 0;
	while (i < ncmds)
	{
		cmd = lc->cmd;
		if (cmd == LC_SYMTAB)
			printf_output((struct symtab_command*)lc, header);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
