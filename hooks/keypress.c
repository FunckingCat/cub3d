#include "./hooks.h"

int	key_press(int keycode, t_state *state)
{
	if (keycode == A_KEY)
		printf("pressed A\n");
	if (keycode == D_KEY)
		printf("pressed D\n");
	if (keycode == S_KEY)
		printf("pressed S\n");
	if (keycode == W_KEY)
		printf("pressed W\n");
	if (keycode == Q_KEY)
		printf("pressed Q\n");
	if (keycode == E_KEY)
		printf("pressed E\n");
	if (keycode == ESC)
		endgame(state);
	return (0);
}