/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:33:50 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 17:33:52 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "ft_printf.h"
# include "ft_unix.h"
# include "libft.h"
# include "list.h"
# include <sys/stat.h>
# include <sys/mman.h>
# include <unistd.h>
# include <fcntl.h>
# include <ar.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>

# define IS_MACHO(a) 	(a == MH_MAGIC)
# define IS_MACHO_64(a) (a == MH_MAGIC_64)
# define IS_FAT(a)	 	(a == FAT_MAGIC || a == FAT_CIGAM)
# define IS_SWAP(a)		(a == MH_CIGAM || a == MH_CIGAM_64 || a == FAT_CIGAM)
# define IS_AR(a)		(!ft_strncmp(a, ARMAG, SARMAG))

# define READ			0
# define WRITE			1
# define OTOOL_OPTIONS	""

int		ft_otool(char const *file, char const *path);
int		handle_32(char const *file, char const *name);
int		handle_64(char const *file, char const *name);
int		handle_fat(char const *file);
int		handle_ar(char const *file, char const *name);

#endif
