/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:08:09 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:11:11 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unix.h"
#include "libft.h"

int	ft_is_option(char c)
{
	char	*opt;

	opt = ft_options_sglt();
	if (!opt)
		return (FAIL);
	else
	{
		if (ft_strchr(opt, c))
			return (c);
		else
			return (FAIL);
	}
}
