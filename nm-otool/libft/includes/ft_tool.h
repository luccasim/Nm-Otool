/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:12:42 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:14:04 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOOL_H
# define FT_TOOL_H

# include <inttypes.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_unix.h"
# include "list.h"
# include "get_next_line.h"
# include "ft_time.h"
# include "ft_random.h"

void	ft_tab_reverse(int32_t *tab, uint32_t size);
void	ft_strdelsplit(char **split);
size_t	ft_strstrlen(char **tab);

#endif
