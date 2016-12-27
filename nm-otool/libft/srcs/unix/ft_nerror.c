/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nerror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:07:59 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:08:01 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unix.h"

int		ft_nerror(int error, int action)
{
	static int	nerror = 0;

	if (action == NERROR_SET)
		nerror = error;
	return (nerror);
}
