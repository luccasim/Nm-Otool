#include <time.h>
#include <stdlib.h>
#include "ft_random.h"

int		ft_random(void)
{
	static int		init = 1;

	if (init)
	{
		init = 0;
		srand(time(NULL));
	}
	return (rand());
}