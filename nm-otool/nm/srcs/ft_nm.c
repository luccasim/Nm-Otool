/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:51:35 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 16:51:37 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		ft_nm(char const *file, char const *path)
{
	uint32_t	magic;

	magic = *(int *)file;
	if (IS_MACHO(magic))
		handle_32(file);
	else if (IS_MACHO_64(magic))
		handle_64(file);
	else if (IS_FAT(magic))
		handle_fat(file);
	else if (IS_AR(file))
		handle_ar(file, path);
	else
		return (PERROR("ft_nm can't recognize this file"));
	return (SUCCESS);
}
