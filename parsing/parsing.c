#include "./parsing.h"

void	validate(int ac ,char **av)
{
	int	conf;

	if (ac == 1)
		put_error_exit(ERR_ARGS_F);
	if (ac > 2)
		put_error_exit(ERR_ARGS_M);
	if (ft_strcmp(".cub", ft_strrchr(av[1], '.')))
		put_ext_error_exit(ERR_CONFIG, ERR_MAP_FORMAT);
	conf = open(av[1], O_RDONLY);
	if (conf == -1)
		put_ext_error_exit(av[1], ERR_FILE);
}