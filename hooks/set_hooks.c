#include "./hooks.h"

int	endgame(t_state *state)
{
	(void)state;
	ft_free();
	exit (EXIT_SUCCESS);
}

void	set_hooks(t_state *state)
{
	mlx_hook(state->win, KEYPRESS, 1L << 0, key_press, state);
	mlx_hook(state->win, KEYEXIT, 1L << 0, endgame, state);
}
