/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:36:17 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/22 04:47:10 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>

# define ENDL			"\n"
# define WORD			"{%s}"
# define NBR			"{y:1:%lli}"

# define PUTSTR(a)		ft_printf("{w:1:%s}\n", a)
# define PUTNBR(a)		ft_printf("{y:1:%lli}\n", a)
# define PUTCHAR(a)		ft_printf("%c\n",a)
# define PUTDB(a)		ft_printf("{c:1:%f}\n", a)
# define PUTBIN(a)		ft_printf("{d:1:%b}\n", a)
# define PUTTIME(a)		ft_printf("{g:1:%hk}\n", a)
# define PUTDATE(a)		ft_printf("{b:1:%lk}\n", a)
# define PUTPTR(a)		ft_printf("{p:1:%p}\n", a)

int		ft_printf(char *str, ...);
int		ft_fprintf(int fd, char *str, ...);

#endif
