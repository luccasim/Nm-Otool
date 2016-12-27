/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:08:29 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:11:38 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unix.h"

static int	catch(int error)
{
	if (error == FT_ERROR_OPEN)
		return (PERROR("open() failed!"));
	else if (error == FT_ERROR_CLOSE)
		return (PERROR("close() failed!"));
	else if (error == FT_ERROR_GNL)
		return (PERROR("Gnl can't read this file"));
	else if (error == FT_ERROR_MALLOC)
		return (PERROR("malloc() failed!"));
	return (error);
}

int			ft_exit(int error)
{
	if (error)
		return (catch(error));
	return (error);
}
