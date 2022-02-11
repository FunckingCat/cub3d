#include "cub.h"

int	main(int ac, char **av) 
{
	validate(ac ,av);
	parse_map(av[1]);
	ft_free();
	return (0);
}