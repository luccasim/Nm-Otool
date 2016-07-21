#include "ft_nm.h"

int main(void)
{
	int fd;
	fd = ft_open("toto", O_RDONLY);
	if (fd)
		ft_printf("{g:4:[%i]}" ENDL, fd);
	return (0);
}