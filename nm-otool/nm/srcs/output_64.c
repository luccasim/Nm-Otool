/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:52:45 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/22 16:52:49 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	check_option(uint64_t *addr, char *symbol)
{
	char	*opt;

	opt = ft_options_sglt();
	if (opt)
	{
		if (ft_strchr(opt, 'u') && ft_strchr(opt, 'U'))
			return (SUCCESS);
		if (ft_strchr(opt, 'u'))
		{
			if (*symbol != 'U')
				return (SUCCESS);
			*addr = 0;
			*symbol = 0;
		}
		if (ft_strchr(opt, 'j'))
		{
			*addr = 0;
			*symbol = 0;
		}
		if (ft_strchr(opt, 'U') && *symbol == 'U')
			return (SUCCESS);
	}
	return (FAIL);
}

int			output_64(void *l, char *st, t_list *sl)
{
	char				symbol;
	uint64_t			value;
	uint64_t			addr;
	uint64_t			name;
	struct nlist_64		*list;

	list = (struct nlist_64*)l;
	addr = 1;
	value = list->n_value;
	symbol = symbol_type(list->n_value, list->n_sect, list->n_type, sl);
	name = 1;
	if (check_option(&addr, &symbol) == SUCCESS)
		return (SUCCESS);
	if (addr)
		addr = (value) ? ft_printf("%.16llx ", value) : ft_printf("%16s ", "");
	if (symbol)
		ft_printf("%c ", symbol);
	if (name)
		ft_printf("%s\n", st + list->n_un.n_strx);
	return (SUCCESS);
}
