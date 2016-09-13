#include "ft_printf.h"

int		ft_error(char *error, char *msg)
{
	ft_fprintf(2, "{r:1:%s}: {w:1:%s}\n", error, msg);
	return (0);
}