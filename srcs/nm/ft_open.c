#include "ft_printf.h"
#include <fcntl.h>
#include <unistd.h>

int		ft_open(char *path, int opt)
{
	int fd;

	if ((fd = open(path, opt)) < 0)
	{
		ft_fprintf(2, "{r:1}Open File %s failed!\n{e}", path);
		_exit(0);
	}
	return (fd);
}