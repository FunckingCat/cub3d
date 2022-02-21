#include "cub.h"

int	main(int ac, char **av) 
{
	t_state state;

	validate(ac ,av);
	state.map = parse_map(av[1]);
	state.pl = new_player(state.map);
	state.mlx = mlx_init();
	state.size = (float)RES_X / (float)state.map->width;
	state.win = mlx_new_window(state.mlx, RES_X, RES_Y, "cub3D");
	render(&state);
	set_hooks(&state);
	mlx_loop(state.mlx);
	return (0);
}
