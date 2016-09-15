#ifndef FT_NM_H
# define FT_NM_H

# include "ft_printf.h"
# include "ft_unix.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>

# define READ		0
# define WRITE		1

void	ft_handle_64(struct mach_header_64 *header);
void	ft_handle(void *header);
int		ft_nm(char* const buf);

#endif 