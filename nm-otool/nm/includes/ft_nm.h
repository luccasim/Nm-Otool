#ifndef FT_NM_H
# define FT_NM_H

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

# define IS_MACHO(a) 	(a == MH_MAGIC || a == MH_CIGAM)
# define IS_MACHO_64(a) (a == MH_MAGIC_64 || a == MH_CIGAM_64)
# define IS_FAT(a)	 	(a == FAT_MAGIC || a == FAT_CIGAM)
# define IS_SWAP(a)		(a == MH_CIGAM || a == MH_CIGAM_64 || a == FAT_CIGAM)
# define IS_AR(a)		(!ft_strncmp(a, ARMAG, SARMAG))

# define READ			0
# define WRITE			1
# define NM_OPTIONS		"puUrj"

typedef struct s_section
{
	char		*name;
	int			nb;
}				t_section;

void	section_del(void *addr, size_t content_size);

char	symbol_type(char value, char sect, char type, t_list *sl);

int		handle_fat(char *const file);
int		handle_ar(char const *file, char const *name);

int		output_32(void *l, char *s, t_list *sl);
int		handle_32(char const *file);

int		output_64(void *l, char *s, t_list *sl);
int		handle_64(char const *file);

int		ft_nm(char* const buf, char const *name);

#endif 