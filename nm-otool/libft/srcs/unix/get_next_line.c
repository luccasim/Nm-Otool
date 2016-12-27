/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:29:39 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/24 11:29:43 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*find_fd(int fd, int first)
{
	static t_list	*list = NULL;
	t_list			*tmp;
	t_list			*new;
	t_fd			content;

	if (first)
		return (list = (first == -1) ? NULL : list);
	content.fd = fd;
	content.str = NULL;
	if (!list)
		return (list = ft_lstnew(&content, sizeof(content)));
	else
	{
		tmp = list;
		while (tmp)
		{
			if (fd == ((t_fd*)(tmp->content))->fd)
				return (tmp);
			new = tmp;
			tmp = tmp->next;
		}
		tmp = ft_lstnew(&content, sizeof(content));
		new->next = tmp;
	}
	return (tmp);
}

static void			free_fd(t_list *del)
{
	char	*str;
	t_list	*alist;
	t_list	*first;

	first = find_fd(0, 1);
	str = (char*)((t_fd*)(del->content))->str;
	if (first == del)
	{
		ft_strdel(&str);
		free(del);
		find_fd(0, -1);
	}
	else
	{
		alist = first;
		while (alist->next != del)
			alist = alist->next;
		alist->next = del->next;
		ft_strdel(&str);
		free(del);
	}
}

static char			*save_line(char *cpy, char **line, int ret)
{
	char	*tmp;
	char	*save;

	save = 0;
	tmp = 0;
	if ((tmp = ft_strchr(cpy, '\n')))
	{
		*tmp = 0;
		*line = ft_strdup(cpy);
		save = ft_strdup(++tmp);
		free(cpy);
		return (save);
	}
	if (0 == ret)
	{
		if (!tmp)
		{
			*line = ft_strdup(cpy);
			free(cpy);
		}
	}
	return (save);
}

static int			read_line(int fd, char **line, t_list *list)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char	*cpy;

	cpy = (char*)((t_fd*)(list->content))->str;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		tmp = cpy;
		cpy = ft_strjoin(tmp, buf);
		free(tmp);
		if ((((t_fd*)(list->content))->str = save_line(cpy, line, ret)))
			return (1);
	}
	if (cpy && ret > -1)
	{
		if (!*cpy)
			return (0);
		((t_fd*)(list->content))->str = save_line(cpy, line, ret);
		return (1);
	}
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	int			ret;
	t_list		*current;

	if (fd < 0 || !line)
		return (-1);
	if (!(current = find_fd(fd, 0)))
		return (-1);
	*line = 0;
	ret = read_line(fd, line, current);
	if (ret == 0)
		free_fd(current);
	return (ret);
}
