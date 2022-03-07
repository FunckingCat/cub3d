/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:11:30 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/07 12:07:09 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hooks.h"

int	endgame(t_state *state)
{
	free_img(state->mlx, state->map->no);
	free_img(state->mlx, state->map->ea);
	free_img(state->mlx, state->map->so);
	free_img(state->mlx, state->map->we);
	mlx_destroy_window(state->mlx, state->win);
	ft_free();
	exit (EXIT_SUCCESS);
}

t_vec	make_step(t_state *state, int dir, int ang)
{
	t_vec	res;

	res.dist = state->size * STEP_SIZE * dir;
	res.angle = state->pl.angle;
	if (ang < 0)
		res.angle -= PI / 2;
	res.x = res.dist * cosf(res.angle);
	res.y = res.dist * sinf(res.angle);
	res = vec_add(state->pl, res);
	if (state->map->map[(int)(res.y / state->size)][(int)(res.x \
		/ state->size)] == '1')
		return (state->pl);
	return (res);
}

int	key_press(int keycode, t_state *state)
{
	if (keycode == W_KEY || keycode == MAC_W_KEY)
		state->pl = make_step(state, -1, 1);
	if (keycode == S_KEY || keycode == MAC_S_KEY)
		state->pl = make_step(state, 1, 1);
	if (keycode == A_KEY || keycode == MAC_A_KEY)
		state->pl = make_step(state, -1, -1);
	if (keycode == D_KEY || keycode == MAC_D_KEY)
		state->pl = make_step(state, 1, -1);
	if (keycode == Q_KEY || keycode == MAC_Q_KEY)
		state->pl.angle -= 2 * DEG;
	if (keycode == E_KEY || keycode == MAC_E_KEY)
		state->pl.angle += 2 * DEG;
	if (keycode == ESC || keycode == MAC_ESC)
		endgame(state);
	if (state->pl.angle > PI * 2)
			state->pl.angle -= PI * 2;
	if (state->pl.angle < 0)
			state->pl.angle += PI * 2;
	render(state);
	return (0);
}

void	set_hooks(t_state *state)
{
	mlx_hook(state->win, KEYPRESS, 1L << 0, key_press, state);
	mlx_hook(state->win, KEYEXIT, 1L << 0, endgame, state);
}
