/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:53:45 by luccasim          #+#    #+#             */
/*   Updated: 2016/09/21 16:53:48 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

# include <time.h>
# include "ft_printf.h"

# define PUTCLOCK(a)		ft_printf("{c:1:%f}\n", ft_cps(a))
# define TIME_ACTION_START	0
# define TIME_ACTION_END	1
# define TIME_START			ft_time(TIME_ACTION_START)
# define TIME_END			ft_time(TIME_ACTION_END)

double	ft_cps(clock_t clock);
void	ft_time(int action);

#endif
