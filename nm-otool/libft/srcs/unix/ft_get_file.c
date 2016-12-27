/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:08:37 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:08:39 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unix.h"
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

t_list	*ft_get_file(const char *path)
{
	t_list		*list;
	t_list		*tmp;
	char		*line;
	int			fd;

	list = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (THROW(FT_ERROR_OPEN));
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!line)
			return (THROW(FT_ERROR_GNL));
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		if (!list)
			list = tmp;
		else
			ft_lstadd_tail(list, tmp);
		ft_strdel(&line);
	}
	if ((fd = close(fd)) < 0)
		THROW(FT_ERROR_CLOSE);
	return (list);
}
