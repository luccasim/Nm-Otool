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
# include "list.h"

# define NERROR_SET		0
# define NERROR_GET		1
# define THROW(a)		ft_throw(a)
# define ERROR			ft_nerror(0, NERROR_GET)
# define PERROR(a) 		ft_perror(a)
# define FT_EXIT		ft_exit(ERROR)

typedef enum	e_ft_error
{
	FT_ERROR_NONE = 0,
	FT_ERROR_OPEN,
	FT_ERROR_GNL,
	FT_ERROR_CLOSE,
	FT_ERROR_MALLOC,
	FT_ERROR
}				t_ft_error;

# define OPT_BUF_SIZE 	100
# define FAIL			0
# define SUCCESS		1
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

int		ft_exit(int error);
void	*ft_throw(int error);
int		ft_nerror(int nerror, int action);
int		ft_error(char *error, char *msg);
int		ft_perror(char *msg);

int		ft_options(char ***av, char *opt, int32_t size);
int		ft_is_option(char c);
t_list	*ft_get_file(const char *path);
t_list	*ft_stdin_file(void);
char	*ft_options_sglt(void);

#endif
