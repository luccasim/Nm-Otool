#include "ft_random.h"

int		ft_rand(int a)
{
	return (ft_random() % (a + 1));
}