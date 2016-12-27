/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:09:03 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/07 15:10:19 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf_atoi(char **arg)
{
	int		sum;
	int		sign;
	char	*str;

	str = *arg;
	sign = 1;
	sum = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + *str - '0';
		str++;
	}
	*arg = str;
	return (sign * sum);
}
