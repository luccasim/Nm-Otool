/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_window_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:01:58 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:02:00 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "ft_printf.h"

void	ft_mlx_window_info(t_window *w)
{
	ft_printf("Window(%p)\t:\n", w);
	ft_printf("mlx\t\t = %p\n", w->mlx);
	ft_printf("win\t\t = %p\n", w->win);
	ft_printf("name\t\t = %s\n", w->name);
	ft_printf("height\t\t = %u\n", w->height);
	ft_printf("width\t\t = %u\n", w->width);
}
