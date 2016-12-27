/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 17:01:02 by luccasim          #+#    #+#             */
/*   Updated: 2016/09/12 17:01:05 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unix.h"
#include "libft.h"

static char	*handle_sglt(char c, uint32_t act)
{
	static uint32_t	flag = 0;
	static uint32_t off = 0;
	static char		sglt[OPT_BUF_SIZE];

	if (act == 0)
	{
		flag = 0;
		off = 0;
		ft_bzero(sglt, OPT_BUF_SIZE);
	}
	if (act == 1)
	{
		if (off == OPT_BUF_SIZE)
		{
			ft_error("Option SGLT", "Buffer_size is full");
			return (sglt);
		}
		sglt[off++] = c;
		flag = 1;
	}
	if (act == 3)
		return ((flag) ? sglt : NULL);
	return (sglt);
}

static int	options_loop(char *str, char *option, char *buf, uint32_t *flag)
{
	if (*str != '-' || !option)
		return (SUCCESS);
	while (*str)
	{
		if (*str == '-')
			str++;
		if (!*str || !ft_strchr(option, *str) || *flag)
			return (ft_error(str, "illegal option"));
		else
		{
			if (ft_strchr(buf, *str) == NULL)
				handle_sglt(*str, 1);
		}
		++str;
	}
	return (-1);
}

static int	number_arg(int32_t nbre_arg, int32_t size)
{
	if (size == 0)
		return (nbre_arg);
	if (size < 0)
	{
		if (nbre_arg > ABS(size))
			return (PERROR("Too much arguments"));
	}
	else
	{
		if (nbre_arg != size)
		{
			ft_fprintf(2, "You have [{r:%i}/{g:%i}] args\n", nbre_arg, size);
			return (FAIL);
		}
	}
	return (nbre_arg);
}

char		*ft_options_sglt(void)
{
	return (handle_sglt(0, 3));
}

int			ft_options(char ***arg, char *opt, int32_t size)
{
	char		**av;
	uint32_t	nbre_arg;
	int32_t		res;

	handle_sglt(0, 0);
	av = *arg;
	nbre_arg = 0;
	av++;
	while (*av)
	{
		res = options_loop(*av, opt, handle_sglt(0, 4), &nbre_arg);
		if (res == FAIL)
			return (FAIL);
		else if (res < 0)
			++av;
		else
		{
			if (!nbre_arg)
				*arg = av;
			++nbre_arg;
			++av;
		}
	}
	return (number_arg(++nbre_arg, size));
}
