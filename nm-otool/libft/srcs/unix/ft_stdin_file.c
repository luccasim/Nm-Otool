/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:08:50 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:08:52 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unix.h"
#include "get_next_line.h"
#include "libft.h"

t_list	*ft_stdin_file(void)
{
	t_list	*buf;
	t_list	*tmp;
	char	*line;

	tmp = 0;
	buf = 0;
	line = 0;
	while (get_next_line(0, &line))
	{
		if (!line)
			return (NULL);
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		if (!buf)
			buf = tmp;
		else
			ft_lstadd_tail(buf, tmp);
		ft_strdel(&line);
	}
	return (buf);
}
