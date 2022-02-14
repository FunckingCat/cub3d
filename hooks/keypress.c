#include "./hooks.h"

int	key_press(int keycode, t_state *state)
{
	if (keycode == W_KEY)
		state->pl->y -= 0.1;
	if (keycode == S_KEY)
		state->pl->y += 0.1;
	if (keycode == A_KEY)
		state->pl->x -= 0.1;
	if (keycode == D_KEY)
		state->pl->x += 0.1;
	if (keycode == Q_KEY)
		state->pl->a -= 0.1;
	if (keycode == E_KEY)
		state->pl->a += 0.1;
	if (keycode == ESC)
		endgame(state);
	render(state);
	return (0);
}