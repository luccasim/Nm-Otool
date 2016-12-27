/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:34:40 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 17:34:43 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static uint32_t	makeswap(uint32_t num)
{
	uint32_t		swapped;

	swapped = ((num >> 24) & 0x000000FF) |
		((num << 8) & 0x00FF0000) |
		((num >> 8) & 0x0000FF00) |
		((num << 24) & 0xFF000000);
	return (swapped);
}

static int		read_fat(struct fat_header *header, int swap, uint32_t nbr)
{
	uint32_t			i;
	void				*obj;
	void				*tmp;
	struct fat_arch		*fat_ar;
	int					cpu_type;

	i = 0;
	tmp = header;
	fat_ar = (struct fat_arch*)(header + 1);
	while (i < nbr)
	{
		obj = tmp;
		cpu_type = (swap) ? makeswap(fat_ar[i].cputype) : fat_ar[i].cputype;
		if (cpu_type == CPU_TYPE_X86_64)
		{
			obj += (swap) ? makeswap(fat_ar[i].offset) : fat_ar[i].offset;
			ft_otool(obj, NULL);
		}
		i++;
	}
	return (SUCCESS);
}

int				handle_fat(char const *file)
{
	struct fat_header	*header;
	int					swap;
	uint32_t			nbr_ar;

	header = (void *)file;
	nbr_ar = *(int*)file;
	swap = IS_SWAP(nbr_ar);
	nbr_ar = (swap) ? makeswap(header->nfat_arch) : header->nfat_arch;
	return (read_fat(header, swap, nbr_ar));
}
