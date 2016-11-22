/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:34:12 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 17:34:14 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int		ft_otool(char const *file, char const *path)
{
	uint32_t	magic;

	magic = *(int*)file;
	if (IS_MACHO_64(magic))
		handle_64(file, path);
	else if (IS_MACHO(magic))
		handle_32(file, path);
	else if (IS_FAT(magic))
		handle_fat(file);
	else if (IS_AR(file))
		handle_ar(file, path);
	else
		return (PERROR("Can't recognize this file!"));
	return (SUCCESS);
}
