/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:52:19 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 16:52:22 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	makeswap(int num)
{
	int		swapped;

	swapped = ((num >> 24) & 0xff) |
		((num << 8) & 0xff0000) |
		((num >> 8) & 0xff00) |
		((num << 24) & 0xff000000);
	return (swapped);
}

static int	read_fat(struct fat_header *header, int swap, uint32_t nbr)
{
	uint32_t			i;
	void				*obj;
	struct fat_arch		*fat_ar;
	int					cpu_type;

	i = 0;
	obj = header;
	fat_ar = (struct fat_arch*)(header + 1);
	while (i < nbr)
	{
		cpu_type = (swap) ? makeswap(fat_ar[i].cputype) : fat_ar[i].cputype;
		if (cpu_type == CPU_TYPE_X86_64)
		{
			if (i < nbr - 1)
			{
				obj += (swap) ? makeswap(fat_ar[i].offset) : fat_ar[i].offset;
				ft_nm(obj, NULL);
			}
		}
		i++;
	}
	return (SUCCESS);
}

int			handle_fat(char const *file)
{
	struct fat_header	*header;
	int					swap;
	uint32_t			nbr_ar;

	header = (void *)file;
	nbr_ar = *(int*)file;
	swap = IS_SWAP(nbr_ar);
	nbr_ar = swap ? makeswap(header->nfat_arch) : header->nfat_arch;
	return (read_fat(header, swap, nbr_ar));
}
