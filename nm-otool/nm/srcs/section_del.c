#include "ft_nm.h"
#include <stdlib.h>

void	section_del(void *addr, size_t content_size)
{
	t_section	*sect;

	sect = (t_section *)addr;
	if (content_size)
	{
		sect->name = NULL;
		sect->nb = 0;
		free(sect);
	}
}