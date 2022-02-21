#include "./hooks.h"

int	key_press(int keycode, t_state *state)
{
	if (keycode == W_KEY)
		state->pl->y -= state->size / 4;
	if (keycode == S_KEY)
		state->pl->y += state->size / 4;
	if (keycode == A_KEY)
		state->pl->x -= state->size / 4;
	if (keycode == D_KEY)
		state->pl->x += state->size / 4;
	if (keycode == Q_KEY)
		state->pl->angle -= 2 * DEG;
	if (keycode == E_KEY)
		state->pl->angle += 2 * DEG;
	if (keycode == ESC)
		endgame(state);
	if (state->pl->angle >= PI * 2)
			state->pl->angle -= PI * 2;
	if (state->pl->angle < 0)
			state->pl->angle += PI * 2;
	render(state);
	return (0);
}