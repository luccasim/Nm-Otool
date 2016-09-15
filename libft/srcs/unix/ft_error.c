/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 14:05:54 by luccasim          #+#    #+#             */
/*   Updated: 2016/09/13 14:06:00 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unix.h"

int		ft_error(char *error, char *msg)
{
	if (!error)
		ft_fprintf(2, "{r:1:%s}\n", msg);
	else if (!msg)
		ft_fprintf(2, "{r:1:%s}: {w:1:%s}\n", error, "error");
	else
		ft_fprintf(2, "{r:1:%s}: {w:1:%s}\n", error, msg);
	return (FAIL);
}
