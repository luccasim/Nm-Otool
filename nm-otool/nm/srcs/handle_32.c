#include "ft_nm.h"

static int	sort_rules(uint32_t *id, struct nlist *l, char *st, uint32_t *t)
{
	char 		*s1;
	char 		*s2;
	char 		*opt;
	int			ret;

	opt = ft_options_sglt();
	s1 = st + l[t[id[0]]].n_un.n_strx;
	s2 = st + l[t[id[1]]].n_un.n_strx;
	ret = ft_strcmp(s1, s2);
	if (ret == 0)
		return (l[t[id[0]]].n_value > l[t[id[1]]].n_value);
	if (!opt)
		return (ret > 0);
	if (ft_strchr(opt, 'p'))
		return (0);
	if (ft_strchr(opt, 'r'))
		return (ret < 0);
	return (ret > 0);
}

static void	sort_table(uint32_t *tab, struct nlist *l, char *st, uint32_t s)
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

static void lc_symtab_32(struct symtab_command *sym, void *header, t_list *sl)
{
	struct nlist 	*list;
	char			*st;
	uint32_t		i;
	uint32_t		tab[sym->nsyms];

	list = header + sym->symoff;
	st = header + sym->stroff;
	i = 0;
	while (i < sym->nsyms)
	{
		tab[i] = i;
		i++;
	}
	sort_table(tab, list, st, sym->nsyms);
	i = 0;
	while (i < sym->nsyms)
	{
		output_32(&list[tab[i]], st, sl);
		i++;
	}
}

static void lc_seg_32(struct segment_command *sc, t_list **sl, uint32_t *n)
{
	uint32_t			i;
	struct section		*s;
	t_section			sect;
	t_list				*new;
	uint32_t			nb;

	i = 0;
	new = 0;
	s = (struct section *)((void *)sc + sizeof(struct segment_command));
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

int			handle_32(char const *file)
{
	struct mach_header			*header;
	struct load_command			*lc;
	t_list						*sl;
	uint32_t					ns;
	uint32_t					i;

	header = (struct mach_header *)file;
	lc = (struct load_command *)(header + 1);
	i = 0;
	sl = 0;
	ns = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			lc_seg_32((struct segment_command*)lc, &sl, &ns);
		}
		if (lc->cmd == LC_SYMTAB)
			lc_symtab_32((struct symtab_command *)lc, header, sl);
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
	ft_lstdel(&sl, section_del);
	return (SUCCESS);
}