#include "ft_printf.h"
#include "libft.h"
#include "ft_nm.h"

static int	insert_buffer(char *buf, char c)
{
	while (*buf)
		buf++;
	*buf = c;
	return (SUCCES);
}

static int	options_loop(char *str, char *option, char *buf)
{
	char *res;

	while (*str)
	{
		res = ft_strchr(option, *str);
		if (!res)
		{
			ft_fprintf(2, "{r:1:%s}: {w:1:%s}\n", str, "illegal option");
			return (FAIL);
		}
		else
		{
			if (ft_strchr(buf, *str) == NULL)
				insert_buffer(buf, *str);
		}
		++str;
	}
	return (SUCCES);
}

static int	number_arg(int32_t nbre_arg, int32_t size)
{
	if (size == 0)
		return (nbre_arg);
	if (size < 0)
	{
		if (nbre_arg > size)
		{
			ft_printf("Too much arguments\n");
			return (FAIL);
		}
	}
	else
	{
		if (nbre_arg != size)
		{
			ft_printf("You have [{r:%i} / {g:%i}] argument(s)\n", nbre_arg,size);
			return (FAIL);
		}
	}
	return (nbre_arg);
}

int			ft_options(char ***arg, char *options, char *buf, int32_t size)
{
	char		*str;
	char		**av;
	uint32_t	nbre_arg;

	ft_bzero(buf, ft_strlen(options));
	av = *arg;
	nbre_arg = 0;
	while (*av)
	{
		str = *av;
		if (str[0] != '-')
			*arg = av;
		else if (options_loop(str, options, buf) == FAIL)
			return (FAIL);
		av++;
		nbre_arg++;
	}
	return (number_arg(nbre_arg, size));
}