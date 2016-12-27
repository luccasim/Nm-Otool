/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:00:53 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:04:25 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "ft_unix.h"
#include "libft.h"

t_image		*ft_mlx_image_new(uint32_t height, uint32_t width)
{
	t_image		*n;
	void		*mlx;
	void		*i;

	if (!(mlx = ft_mlx_init_sglt()))
		return (NULL);
	if ((n = ft_memalloc(sizeof(t_image))))
	{
		if ((i = mlx_new_image(mlx, width, height)))
		{
			n->mlx = mlx;
			n->img = i;
			n->addr = mlx_get_data_addr(i, &n->bpp, &n->size_line, &n->endian);
			n->height = height;
			n->width = width;
		}
		else
		{
			PERROR("mlx_new_image() failed!");
			return (NULL);
		}
	}
	return (n);
}
