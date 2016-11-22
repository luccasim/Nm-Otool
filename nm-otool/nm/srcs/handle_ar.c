/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:52:07 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 16:52:09 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static uint32_t	ar_size(char const *name)
{
	char *size;

	size = ft_strchr(name, '/');
	return (ft_atoi(size + 1));
}

static int		read_ranlib(char const *file, char const *name, uint32_t nbr)
{
	struct ar_hdr	*ar;
	void			*obj;
	struct ranlib	*ranlib;
	uint32_t		i;

	i = 0;
	ar = (void*)file + SARMAG;
	ranlib = (void*)ar + sizeof(struct ar_hdr) + ar_size(ar->ar_name) + 4;
	while (i < nbr)
	{
		ar = (void*)file + ranlib[i].ran_off;
		obj = (void*)ar + sizeof(struct ar_hdr) + ar_size(ar->ar_name);
		ft_printf("\n%s(%s):\n", name, ar->ar_name + sizeof(struct ar_hdr));
		ft_nm(obj, name);
		i++;
	}
	return (SUCCESS);
}

int				handle_ar(char const *file, char const *name)
{
	struct ar_hdr	*ar;
	int				nobj;

	ar = (void *)file + SARMAG;
	nobj = *((int *)((void*)ar + sizeof(struct ar_hdr) + ar_size(ar->ar_name)));
	nobj = nobj / sizeof(struct ranlib);
	return (read_ranlib(file, name, nobj));
}
