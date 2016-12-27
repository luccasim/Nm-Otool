/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init_sglt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:01:27 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:01:30 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "ft_unix.h"

void	*ft_mlx_init_sglt(void)
{
	static void		*mlx = NULL;

	if (!mlx)
	{
		if (!(mlx = mlx_init()))
		{
			PERROR("mlx_init() connexion fail");
			return (mlx);
		}
	}
	return (mlx);
}
