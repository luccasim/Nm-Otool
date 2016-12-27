/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:00:41 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:00:45 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "ft_printf.h"

void	ft_mlx_image_info(t_image *img)
{
	ft_printf("Image(%p)\t:\n", img);
	ft_printf("mlx\t\t = %p\n", img->mlx);
	ft_printf("img\t\t = %p\n", img->img);
	ft_printf("addr\t\t = %p\n", img->addr);
	ft_printf("height\t\t = %u\n", img->height);
	ft_printf("width\t\t = %u\n", img->width);
	ft_printf("bpp\t\t = %i\n", img->bpp);
	ft_printf("endian\t\t = %i\n", img->endian);
	ft_printf("size_line\t = %i\n", img->size_line);
}
