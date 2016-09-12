#include "ft_nm.h"
#include <sys/mman.h>

int main(int ac, char **av)
{
	char	*file;
	char	buf[3];

	if (ac == ft_options(&av, "abc", buf, 3))
	{
		while (*av)
		{
			file = 0;
			file = ft_mapfile(*av);
			ft_nm(file);
			av++;
		}
	}
	return (0);
}