#include "cub.h"

int	main(int ac, char **av) 
{
	t_map *map;

	validate(ac ,av);
	map = parse_map(av[1]);
	print_map(map);
	ft_free();
	return (0);
}