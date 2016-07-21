#ifndef FT_NM_H
# define FT_NM_H

# include "ft_printf.h"
# include <sys/stat.h>
# include <fcntl.h>

# define PUTS(a) ft_printf(a ENDL);

int		ft_open(char *path, int opt);

#endif 