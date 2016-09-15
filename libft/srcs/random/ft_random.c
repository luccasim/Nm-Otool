/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 03:55:44 by luccasim          #+#    #+#             */
/*   Updated: 2016/07/20 03:55:48 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "ft_random.h"

int		ft_random(void)
{
	static int		init = 1;

	if (init)
	{
		init = 0;
		srand(time(NULL));
	}
	return (rand());
}
