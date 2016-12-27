/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image_pixel_get.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:01:06 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:01:08 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

uint32_t	ft_mlx_image_pixel_get(t_image *img, int x, int y)
{
	int			pix;
	uint32_t	color;
	uint32_t	a;
	uint32_t	b;

	color = 0;
	if (x < 0 || y < 0)
		return (color);
	a = (uint32_t)x;
	b = (uint32_t)y;
	if (a < img->width && b < img->height)
	{
		pix = b * img->size_line + b * (img->bpp / 8);
		color = *(int *)(&img->addr + pix);
	}
	return (color);
}
