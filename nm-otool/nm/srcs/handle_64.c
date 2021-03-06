/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:51:58 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 16:52:00 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	sort_rules(uint64_t *id, struct nlist_64 *l, char *st, int64_t *t)
{
	char		*s1;
	char		*s2;
	char		*opt;
	int			ret;

	opt = ft_options_sglt();
	s1 = st + l[t[id[0]]].n_un.n_strx;
	s2 = st + l[t[id[1]]].n_un.n_strx;
	ret = ft_strcmp(s1, s2);
	if (ret == 0)
		return (l[t[id[0]]].n_value > l[t[id[1]]].n_value);
	if (!opt)
		return (ret > 0);
	return (ret > 0);
}

static void	sort_table(int64_t *tab, struct nlist_64 *l, char *st, uint64_t s)
{
	uint64_t	i;
	uint64_t	j;
	uint64_t	id[2];
	uint64_t	tmp;

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

static void	lc_symtab_64(struct symtab_command *sym, void *header, t_list *sl)
{
	struct nlist_64 *list;
	char			*st;
	uint64_t		i;
	int64_t			tab[sym->nsyms];

	list = header + sym->symoff;
	st = header + sym->stroff;
	i = 0;
	while (i < sym->nsyms)
	{
		tab[i] = i;
		i++;
	}
	if (!ft_is_option('p'))
	{
		sort_table(tab, list, st, sym->nsyms);
		if (ft_is_option('r'))
			ft_tab_reverse_64(tab, i);
	}
	i = 0;
	while (i < sym->nsyms)
		output_64(&list[tab[i++]], st, sl);
}

static void	lc_seg_64(struct segment_command_64 *sc, t_list **sl, uint64_t *n)
{
	uint64_t			i;
	struct section_64	*s;
	t_section			sect;
	t_list				*new;
	uint64_t			nb;

	i = 0;
	new = 0;
	s = (struct section_64 *)((void *)sc + sizeof(struct segment_command_64));
	nb = *n;
	while (i < sc->nsects)
	{
		sect.name = s[i].sectname;
		sect.nb = ++nb;
		new = ft_lstnew(&sect, sizeof(sect));
		if (new)
			ft_lstadd(sl, new);
		i++;
	}
	*n = nb;
}

int			handle_64(char const *file)
{
	struct mach_header_64		*header;
	struct load_command			*lc;
	t_list						*sl;
	uint64_t					ns;
	uint64_t					i;

	header = (struct mach_header_64 *)file;
	lc = (struct load_command *)(header + 1);
	i = 0;
	sl = 0;
	ns = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			lc_seg_64((struct segment_command_64*)lc, &sl, &ns);
		}
		if (lc->cmd == LC_SYMTAB)
			lc_symtab_64((struct symtab_command *)lc, header, sl);
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
	ft_lstdel(&sl, section_del);
	return (SUCCESS);
}
