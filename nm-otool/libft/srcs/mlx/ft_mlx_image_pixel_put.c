/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image_pixel_put.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:01:16 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:01:18 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "libft.h"

void	ft_mlx_image_pixel_put(t_image *img, int x, int y, int c)
{
	int			pix;
	uint32_t	color;
	uint32_t	a;
	uint32_t	b;

	if (x < 0 || y < 0)
		return ;
	a = (uint32_t)x;
	b = (uint32_t)y;
	if (a < img->width && b < img->height)
	{
		pix = b * img->size_line + a * (img->bpp / 8);
		color = mlx_get_color_value(ft_mlx_init_sglt(), c);
		ft_memcpy(&(img->addr[pix]), &(color), 4);
	}
}
