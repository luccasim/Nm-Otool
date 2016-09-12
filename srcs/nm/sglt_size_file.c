#include "ft_nm.h"

size_t	sglt_size_file(size_t size, int act)
{
	static size_t ret = 0;

	if (act == WRITE)
		ret = size;
	return (size);
}