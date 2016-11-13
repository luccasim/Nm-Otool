#include "ft_otool.h"

static int		munmap_file(char *adr, struct stat *buf)
{
	int		error;

	if (!buf || !adr)
		return (PERROR("munmap_file one parameter given is NULL"));
	error = munmap(adr, buf->st_size);
	if (error)
		return (PERROR("munmap"));
	adr = NULL;
	return (SUCCESS);
}

static int		mmap_file(char *path, struct stat *buf, char **addr)
{
	void	*file;
	int		fd;

	file = *addr;
	if (*path == '-')
		return (FAIL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (PERROR("open"));
	if (fstat(fd, buf) < 0)
		return (PERROR("fstat"));
	if ((buf->st_mode & S_IFMT) == S_IFDIR)
		return (PERROR("Can't read a directory"));
	file = mmap(0, buf->st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (!file)
		return (PERROR("mmap"));
	if (close(fd) < 0)
		return (PERROR("close"));
	*addr = file;
	return (SUCCESS);
}

int 			main(int ac, char **av)
{
	char 		*path;
	char		*file;
	struct stat	buf;

	ac = ft_options(&av, OTOOL_OPTIONS, 0);
	path = 0;
	file = 0;
	if (ac)
	{
		while (*av)
		{
			path = *av;
			file = 0;
			if (ac == 1)
				path = "a.out";
			if (mmap_file(path, &buf, &file) == SUCCESS)
			{
				ft_otool(file, path);
				munmap_file(file, &buf);
			}
			av++;
		}
	}
	return (EXIT_SUCCESS);
}