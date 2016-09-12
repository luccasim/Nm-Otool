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

static int	options_loop(char *str, char *option, char *buf, uint32_t *flag)
{
	if (*str != '-' || !option)
		return (SUCCES);
	while (*str)
	{
		if (*str == '-')
			str++;
		if (!*str || !ft_strchr(option, *str) || *flag)
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
	return (-1);
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
			ft_printf("You have [{r:%i}/{g:%i}] args\n", nbre_arg, size);
			return (FAIL);
		}
	}
	return (nbre_arg);
}

int			ft_options(char ***arg, char *options, char *buf, int32_t size)
{
	char		**av;
	uint32_t	nbre_arg;
	int32_t		res;

	ft_bzero(buf, ft_strlen(options));
	av = *arg;
	nbre_arg = 0;
	av++;
	while (*av)
	{
		res = options_loop(*av, options, buf, &nbre_arg);
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
	nbre_arg++;
	return (number_arg(nbre_arg, size));
}
