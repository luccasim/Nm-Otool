/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 17:00:49 by luccasim          #+#    #+#             */
/*   Updated: 2016/09/12 17:00:53 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <sys/mman.h>
#include "libft.h"
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

/*
static void		init_table(uint32_t *tab, uint32_t size)
{
	uint32_t i;

	i = 0;
	while (i < size)
	{
		tab[i] = i;
		i++;
	}
}
*/
/*
static void print_tab(uint32_t *tab, uint32_t size)
{
	uint32_t j = 0;

	ft_printf("Tableau :\n");
	while (j < size)
	{
		ft_printf("[%i]", tab[j]);
		j++;
	}
	ft_printf(ENDL);
}
*/
/*
static void		sort_table(uint32_t *tab, struct nlist_64 *list, char * stab, uint32_t size)
{
	uint32_t min;
	uint32_t i;
	uint32_t j;

	init_table(tab, size);
	i = 0;
	min = tab[i];
	j = size;
	while (j--)
	{
		i = 0;
		while (i < j)
		{
			if (ft_strcmp(stab + list[tab[i]].n_un.n_strx,stab + list[tab[j]].n_un.n_strx) > 0)
			{
				min = tab[j];
				tab[j] = tab[i];
				tab[i] = min;
			}
			i++;
		}
	}
}
*/
/*
static void		handle_64(struct mach_header_64 *header)
{
	uint32_t				ncmds;
	struct load_command		*lc;
	struct nlist_64			*array;
	char 					*stringtab;
	struct symtab_command	*sym;
	uint32_t				i;

	ncmds = header->ncmds;
	lc = (struct load_command*)(header + 1);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			ft_printf("Symtab_commande :\n");
			ft_printf("Symtab com : %i\n", sym->cmd);
			ft_printf("Symtab com_size : %i\n", sym->cmdsize);
			ft_printf("Symtab symoff : %i\n", sym->symoff);
			ft_printf("Symtab nsyms : %i\n", sym->nsyms);
			ft_printf("Symtab stroff : %u\n", sym->stroff);
			ft_printf("Symtab strsize : %u\n", sym->strsize);
			array = (void *)header + sym->symoff;
			stringtab = (void*)header + sym->stroff;
			uint32_t j = 0;
			uint32_t tab[sym->nsyms];
			sort_table(tab, array, stringtab, sym->nsyms);
			while (j < sym->nsyms)
			{
				//ft_printf("{w:0:%.16llx} {y:1:%i} {w:1:%s}\n", array[tab[j]].n_value, array[tab[j]].n_type & N_PEXT, stringtab + array[tab[j]].n_un.n_strx);
				ft_printf("{w:0:%.16llx} ", array[tab[j]].n_value);
				ft_printf("{y:1:%i} ", array[tab[j]].n_type & N_STAB);
				ft_printf("{y:1:%i} ", array[tab[j]].n_type & N_PEXT);
				ft_printf("{y:1:%i} ", array[tab[j]].n_type & N_TYPE);
					ft_printf("{b:1:%i} ", array[tab[j]].n_type & N_UNDF);
					ft_printf("{b:1:%i} ", array[tab[j]].n_type & N_ABS);
					ft_printf("{w:1:%i} ", array[tab[j]].n_type & N_SECT);
						ft_printf("{w:1:%i} ", array[tab[j]].n_sect);
					ft_printf("{b:1:%i} ", array[tab[j]].n_type & N_PBUD);
					ft_printf("{b:1:%i} ", array[tab[j]].n_type & N_INDR);
						ft_printf("{g:1:%i}",stringtab + array[tab[j]].n_value);
				ft_printf("{y:1:%i} ", array[tab[j]].n_type & N_EXT);
				ft_printf("{w:1:%s}\n",stringtab + array[tab[j]].n_un.n_strx);
				j++;
			}
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
*/

static void		read_binary(char *file)
{
	struct mach_header 		*header;
	struct mach_header_64 	*header_64;
	uint32_t				magic;

	magic = *(uint32_t *)file;
	// ft_printf("Valeur de MH_MAGIC_64 : {b:1:%llu}\n",MH_MAGIC_64);
	// ft_printf("Valeur de MH_CIGAM_64 : {b:1:%llu}\n",MH_CIGAM_64);
	// ft_printf("Valeur de MH_MAGIC : {b:1:%llu}\n",MH_MAGIC);
	// ft_printf("Valeur de MH_CIGAM : {b:1:%llu}\n",MH_CIGAM);
	ft_printf("The magic number is {g:1:%llu}\n",magic);
	if (magic == MH_MAGIC_64)
	{
		header_64 = (struct mach_header_64 *)file;
		ft_handle_64(header_64);
	}
	else
	{
		header = (struct mach_header *)file;
		ft_handle(header);
	}
}

int		ft_nm(char* const path)
{
	int			fd;
	struct stat	buf;
	char		*file;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (PERROR("open"));
	if (fstat(fd, &buf) < 0)
		return (PERROR("fstat"));
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (ft_fprintf(2, "Can't read a directory\n"));
	file = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (close(fd) < -1)
		return (PERROR("close"));
	read_binary(file);
	munmap(file, buf.st_size);
	return (SUCCES);
}
