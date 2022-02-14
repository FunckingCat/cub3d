#include "./hooks.h"

int	key_press(int keycode, t_state *state)
{
	if (keycode == W_KEY)
		state->pl->y -= state->pl->size / 3;
	if (keycode == S_KEY)
		state->pl->y += state->pl->size / 3;
	if (keycode == A_KEY)
		state->pl->x -= state->pl->size / 3;
	if (keycode == D_KEY)
		state->pl->x += state->pl->size / 3;
	if (keycode == Q_KEY)
		state->pl->a -= 0.1;
	if (keycode == E_KEY)
		state->pl->a += 0.1;
	if (keycode == ESC)
		endgame(state);
	state->pl->grid_x = grid_coord(state->pl, state->pl->x);
	state->pl->grid_y = grid_coord(state->pl, state->pl->y);
	render(state);
	return (0);
}