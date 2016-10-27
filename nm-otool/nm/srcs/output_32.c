#include "ft_nm.h"

static int	check_option(uint32_t *addr, char *symbol)	
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

int			output_32(void *l, char *st, t_list *sl)
{
	char				symbol;
	uint32_t 			value;
	uint32_t 			addr;
	uint32_t			name;
	struct nlist 		*list;

	list = (struct nlist *)l;
	addr = 1;
	value = list->n_value;
	symbol = symbol_type(list->n_value, list->n_sect, list->n_type, sl);
	name = 1;
	if (check_option(&addr, &symbol) == SUCCESS)
		return (SUCCESS);
	if (addr)
		addr = (value) ? ft_printf("%.8llx ", value) : ft_printf("%8s ", "");
	if (symbol)
		ft_printf("%c ", symbol);
	if (name)
		ft_printf("%s\n", st + list->n_un.n_strx);
	return (SUCCESS);
}