/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:34:58 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 17:35:00 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int	print_section(struct section *s, char const *h)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	addr;
	uint32_t	off;
	char		c;

	i = 0;
	addr = s->addr;
	off = s->offset;
	while (i < s->size)
	{
		j = 0;
		ft_printf("%0.8llx\t", addr);
		while (j < 16 && i + j < s->size)
		{
			c = *(h + off);
			ft_printf("%.2hhx ", c);
			off++;
			j++;
		}
		ft_printf("\n");
		i += j;
		addr += j;
	}
	return (SUCCESS);
}

static int	lc_seg_32(struct segment_command *sc, char const *h)
{
	uint32_t			i;
	struct section		*s;
	char				*str;

	i = 0;
	s = (struct section*)(sc + 1);
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

int			handle_32(char const *file, char const *name)
{
	struct mach_header		*header;
	struct load_command		*lc;
	uint32_t				i;

	header = (struct mach_header*)file;
	lc = (struct load_command*)(header + 1);
	i = 0;
	if (name)
		ft_printf("%s:\n", name);
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			lc_seg_32((struct segment_command*)lc, file);
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
	return (SUCCESS);
}
