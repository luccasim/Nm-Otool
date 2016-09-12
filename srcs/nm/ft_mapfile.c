#include "ft_nm.h"
#include <sys/mman.h>
#include <unistd.h>

static char*	mapfile(int fd)
{
	struct stat buf;
	char 		*ret;

	ret = 0;
	if (fstat(fd, &buf) < 0)
	{
		PERROR("fstat");
		return (ret);
	}
	else
	{
		sglt_size_file(buf.st_size, WRITE);
		ret = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	}
	return (ret);
}

char*	ft_mapfile(char* const path)
{
	int			fd;
	char		*file;

	PUTS("mapfile called !");
	file = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		PERROR("open");
		return (file);
	}
	else
		file = mapfile(fd);
	if (close(fd) < 0)
		PERROR("close");
	return (file);
}