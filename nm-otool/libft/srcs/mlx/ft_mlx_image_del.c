/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:00:14 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:00:16 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include <stdlib.h>

void	ft_mlx_image_del(t_image *img)
{
	void	*mlx;

	mlx = ft_mlx_init_sglt();
	if (img && mlx)
	{
		mlx_destroy_image(mlx, img);
		free(img);
	}
}
