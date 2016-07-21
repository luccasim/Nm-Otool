#include "ft_random.h"
#include "libft.h"

int		ft_rand_ab(int a, int b)
{
	return (ft_rand(ABS(a, b)) + MIN(a, b));
}