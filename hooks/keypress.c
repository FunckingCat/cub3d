#include "./hooks.h"

int	key_press(int keycode, t_state *state)
{
	if (keycode == W_KEY)
		state->pl->x += 0.4;
	if (keycode == S_KEY)
		state->pl->x -= 0.4;
	if (keycode == A_KEY)
		state->pl->y -= 0.4;
	if (keycode == D_KEY)
		state->pl->y += 0.4;
	if (keycode == Q_KEY)
	{
		state->pl->a += 5.0f;
		if (state->pl->a == 360.0f)
			state->pl->a = 0.0f;
	}
	if (keycode == E_KEY)
	{
		state->pl->a -= 5.0f;
		if (state->pl->a == 0.0f)
			state->pl->a = 360.0f;
	}
	if (keycode == ESC)
		endgame(state);
	//print_player(state->pl);
	render(state);
	return (0);
}