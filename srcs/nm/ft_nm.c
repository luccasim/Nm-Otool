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

static void		read_binary(char *file)
{
	struct mach_header 		*header;
	struct mach_header_64 	*header_64;
	uint32_t				magic;

	magic = *(uint32_t *)file;
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
