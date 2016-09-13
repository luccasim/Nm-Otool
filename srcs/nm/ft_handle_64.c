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
#include "libft.h"

static int	sort_rules(uint32_t *id, struct nlist_64 *l, char *st, uint32_t *t)
{
	char 		*s1;
	char 		*s2;
	char 		*opt;

	opt = ft_options_sglt();
	s1 = st + l[t[id[0]]].n_un.n_strx;
	s2 = st + l[t[id[1]]].n_un.n_strx;
	if (ft_strchr(opt, 'r'))
		return (ft_strcmp(s1, s2) < 0);
	return (ft_strcmp(s1, s2) > 0);
}

static void	sort_table(uint32_t *tab, struct nlist_64 *l, char *st, uint32_t s)
{
	uint32_t	i;
	uint32_t 	j;
	uint32_t	id[2];
	uint32_t	tmp;

	j = s;
	tmp = tab[0];
	while (j--)
	{
		i = 0;
		while (i < j)
		{
			id[0] = i;
			id[1] = j;
			if (sort_rules(id, l, st, tab))
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			i++;
		}
	}
}

static int get_segment(int i)
{
	if (i == 11)
		return ('b');
	if (i == 10)
		return ('d');
	if (i == 1)
		return ('t');
	if (i == 0)
		return ('u');
	return ('s');
}

static void	print_op(uint32_t *t, struct nlist_64 *l, char *st, uint32_t i)
{
	char 	seg;
	int		value;

	seg = get_segment(l[t[i]].n_sect);
	seg = (l[t[i]].n_type & N_EXT) ? ft_toupper(seg) : seg;
	value = l[t[i]].n_value;
	ft_printf("{%.2x}{%.2x}", l[t[i]].n_type, N_STAB);
	if (value)
		ft_printf("%.16llx ", value);
	else
		ft_printf("%16s ", "");
	ft_printf("%c ", seg);
	ft_printf("%s", st + l[t[i]].n_un.n_strx);
	ft_printf(ENDL);
}

static void	handle_symtab(struct symtab_command *sym, void *header)
{
	struct nlist_64	*list;
	char			*stringtab;
	uint32_t		i;
	uint32_t		tab[sym->nsyms];

	list = header + sym->symoff;
	stringtab = header + sym->stroff;
	i = 0;
	while (i < sym->nsyms)
	{
		tab[i] = i;
		i++;
	}
	sort_table(tab, list, stringtab, sym->nsyms);
	i = 0;
	while (i < sym->nsyms)
	{
		print_op(tab, list, stringtab, i);
		// ft_printf("%s\n",stringtab + list[tab[i]].n_un.n_strx);
		i++;
	}
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
			handle_symtab((struct symtab_command*)lc, header);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
