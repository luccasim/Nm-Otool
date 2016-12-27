/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_window_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:02:09 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:02:12 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "libft.h"
#include "ft_unix.h"

t_window	*ft_mlx_window_new(char *name, uint32_t height, uint32_t width)
{
	t_window	*new;
	void		*mlx;

	mlx = ft_mlx_init_sglt();
	new = 0;
	if (mlx)
	{
		new = ft_memalloc(sizeof(t_window));
		if (new)
		{
			new->win = mlx_new_window(mlx, width, height, name);
			new->height = height;
			new->width = width;
			new->name = name;
			new->mlx = mlx;
		}
		else
			PERROR("fail allocation for window ptr");
	}
	return (new);
}
