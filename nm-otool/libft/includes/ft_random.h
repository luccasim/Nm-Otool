/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 03:57:24 by luccasim          #+#    #+#             */
/*   Updated: 2016/07/20 03:57:27 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_H
# define FT_RANDOM_H

# define RAND(a) ft_rand_ab(0 , a)

int		ft_random(void);
int		ft_rand(int a);
int		ft_rand_ab(int a, int b);

#endif
