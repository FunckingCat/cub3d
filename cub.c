#include "cub.h"

int	main(int ac, char **av) 
{
	t_state state;

	validate(ac ,av);
	state.map = parse_map(av[1]);
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, RES_X, RES_Y, "cub3D");
	mlx_loop(state.mlx);
	ft_free();
	return (0);
}