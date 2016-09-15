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

# define WORD_OPT	"w:1"
# define NBR_OPT	"y:1"
# define WORD_LEN	"0"

# define ENDL		"\n"
# define WORD		"{" WORD_OPT "}%" WORD_LEN "s{e}"
# define NBR(a)		"{" WORD_OPT "}" #a " = {e}{" NBR_OPT "}%lli{e}"

# define PUTS(a)		ft_printf(WORD ENDL, a)

int		ft_printf(char *str, ...);
int		ft_fprintf(int fd, char *str, ...);

#endif
