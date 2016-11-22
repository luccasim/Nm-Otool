/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:35:12 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 17:35:15 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int	print_section(struct section_64 *s, char const *h)
{
	uint64_t	i;
	uint64_t	j;
	uint64_t	addr;
	uint64_t	off;

	i = 0;
	addr = s->addr;
	off = s->offset;
	while (i < s->size)
	{
		j = 0;
		ft_printf("%0.16llx\t", addr);
		while (j < 16 && i + j < s->size)
		{
			ft_printf("%.2hhx ", *(h + off));
			off++;
			j++;
		}
		ft_printf("\n");
		i += j;
		addr += j;
	}
	return (SUCCESS);
}

static int	lc_seg_64(struct segment_command_64 *sc, char const *h)
{
	uint64_t			i;
	struct section_64	*s;
	char				*str;

	i = 0;
	s = (struct section_64*)(sc + 1);
	str = SECT_TEXT;
	while (i < sc->nsects)
	{
		if (ft_strequ(s[i].sectname, SECT_TEXT)
			&& ft_strequ(s[i].segname, SEG_TEXT))
		{
			ft_printf("Contents of (%s,%s) section\n", SEG_TEXT, SECT_TEXT);
			print_section(s + i, h);
		}
		i++;
	}
	return (SUCCESS);
}

int			handle_64(char const *file, char const *name)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	uint64_t				i;

	header = (struct mach_header_64*)file;
	lc = (struct load_command*)(header + 1);
	i = 0;
	if (name)
		ft_printf("%s:\n", name);
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			lc_seg_64((struct segment_command_64*)lc, file);
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
	return (SUCCESS);
}
