/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:04:24 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/03 17:27:16 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

void	render_rays(t_state *state, t_img *img, t_vec **rays, float scale)
{
	float	size;
	size_t	i;
	t_vec	vec;

	i = 0;
	size = (RES_X * scale) / state->map->width;
	while (i < RES_X - 1)
	{
		vec.x = rays[i]->x * size;
		vec.y = rays[i]->y * size;
		put_pixel(img, (int)(vec.x), (int)(vec.y), COL_YELLOW);
		i += 8;
	}
}

void	render_player(t_state *state, t_img *img, float scale)
{
	size_t	pl_size;
	size_t	i;
	size_t	j;
	size_t	dx;
	size_t	dy;

	pl_size = state->size / 3;
	i = state->pl.x - pl_size;
	while (i < state->pl.x + pl_size)
	{
		j = state->pl.y - pl_size;
		while (j < state->pl.y + pl_size)
		{
			dx = i - state->pl.x;
			dy = j - state->pl.y;
			if (dx * dx + dy * dy < pl_size * pl_size)
				put_pixel(img, i * scale, j * scale, COL_GREEN);
			j++;
		}
		i++;
	}
	put_pixel(img, state->pl.x * scale, state->pl.y * scale, COL_RED);
}

void	draw_rec(t_img *img, t_rec *rec)
{
	int	i;
	int	j;

	i = rec->x;
	while (i < rec->width + 1)
	{
		j = rec->y;
		while (j < rec->height + 1)
		{
			if (i == rec->x || j == rec->y || \
				i == rec->width || j == rec->height)
				put_pixel(img, i, j, COL_DGRAY);
			else
				put_pixel(img, i, j, rec->color);
			j++;
		}
		i++;
	}
}

float	calc_scale(t_state *state)
{
	int	max_width;

	max_width = (int)floorf(RES_X * MINI_MAP_W);
	while (max_width % state->map->width != 0)
		max_width--;
	return ((float)max_width / (float)RES_X);
}

void	render_minimap(t_state *state, t_img *img, t_vec **rays)
{
	t_rec	rec;
	float	scale;
	size_t	i;
	size_t	j;

	i = 0;
	scale = calc_scale(state);
	while (i < state->map->height)
	{
		j = 0;
		while (j < state->map->width)
		{
			rec.x = (int)(j * state->size * scale);
			rec.y = (int)(i * state->size * scale);
			rec.width = (int)(rec.x + state->size * scale);
			rec.height = (int)(rec.y + state->size * scale);
			rec.color = COL_LGRAY;
			if (!ft_strchr(" 1", state->map->map[i][j]))
				draw_rec(img, &rec);
			j++;
		}
		i++;
	}
	render_player(state, img, scale);
	render_rays(state, img, rays, scale);
}
