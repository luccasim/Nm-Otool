/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:04:54 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:04:56 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time.h"

void	ft_time(int action)
{
	static clock_t	start;
	static clock_t	end;
	static time_t	tstart;
	static time_t	tend;

	if (action == TIME_ACTION_START)
	{
		start = clock();
		tstart = time(NULL);
		ft_printf("{d:1:%s}\n", "Time action start");
	}
	else if (action == TIME_ACTION_END)
	{
		end = clock();
		tend = time(NULL);
		ft_printf("{d:1}Clock at start:\t\t%u{e}\n", start);
		ft_printf("{d:1}Clock at end:\t\t%u{e}\n", end);
		ft_printf("{d:1}Clock time used:\t%u{e}\n", end - start);
		ft_printf("{d:1}Estimated Clock time:\t%f{e}\n", ft_cps(end - start));
		ft_printf("{d:1}Estimated time (sec):\t%u{e}\n", tend - tstart);
	}
}
