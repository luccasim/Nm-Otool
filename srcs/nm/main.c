/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 17:01:10 by luccasim          #+#    #+#             */
/*   Updated: 2016/09/12 17:01:12 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include "libft.h"
#include <sys/mman.h>

int		main(int ac, char **av)
{
	char	*file;
	char	*opt;

	opt = "j";
	ac = ft_options(&av, opt, 0);
	if (ac)
	{
		while (*av)
		{
			file = *av;
			ft_nm(file);
			av++;
		}
	}
	return (0);
}
