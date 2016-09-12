#ifndef FT_NM_H
# define FT_NM_H

# include "ft_printf.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>

# define PUTS(a) 	ft_printf(a ENDL)
# define PERROR(a) 	ft_fprintf(2, "{r:1:%s}: {w:1:%s}" ENDL, a, "error")
# define READ		0
# define WRITE		1
# define FAIL		0
# define SUCCES		1


int		ft_options(char ***av, char *options, char *buf, int32_t size);
void	ft_handle_64(struct mach_header_64 *header);
void	ft_handle(void *header);
int		ft_nm(char* const buf);

#endif 