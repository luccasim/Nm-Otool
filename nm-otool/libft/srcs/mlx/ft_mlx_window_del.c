/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_window_del.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:01:46 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:01:49 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include <stdlib.h>
#include <unistd.h>

void		ft_mlx_window_del(t_window *win)
{
	if (win)
	{
		if (win->win)
			mlx_destroy_window(win->mlx, win->win);
		free(win);
		_exit(1);
	}
}
