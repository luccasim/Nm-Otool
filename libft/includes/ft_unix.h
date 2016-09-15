/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:29:37 by luccasim          #+#    #+#             */
/*   Updated: 2016/09/14 15:29:39 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNIX_H
# define FT_UNIX_H

# include "ft_printf.h"

# define ERROR(a) 		ft_error(0, a)
# define PERROR(a) 		ft_error(a, "error")
# define OPT_BUF_SIZE 	100
# define FAIL			0
# define SUCCES			1

int		ft_error(char *error, char *msg);
int		ft_options(char ***av, char *opt, int32_t size);
char	*ft_options_sglt(void);

#endif
