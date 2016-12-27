/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:24:37 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 16:24:41 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tool.h"
#include <unistd.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	if (ac == 2)
	{
		line = 0;
		fd = open(*++av, O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			PUTSTR(line);
			ft_strdel(&line);
		}
	}
	return (0);
}
