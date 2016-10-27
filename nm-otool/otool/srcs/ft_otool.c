#include "ft_otool.h"

int		ft_otool(char const *file, char const *path)
{
	uint32_t	magic;
	
	magic = *(int*)file;
	if (IS_MACHO_64(magic))
		handle_64(file, path);
	if (IS_MACHO(magic))
		handle_32(file, path);
	else if (IS_FAT(magic))
		handle_fat(file);
	else if (IS_AR(file))
		handle_ar(file, path);
	else
		return (ERROR("Can't recognize this file!"));
	return (SUCCESS);
}