/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 07:02:27 by rusty             #+#    #+#             */
/*   Updated: 2022/02/16 17:16:21 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_vec	find_intersection(t_vec plr, t_vec dir, float dist)
{
	t_vec	ret;
	t_vec	ray;

	ray = vec_mul(dir, dist);
	ret = vec_add(plr, ray);
	return (ret);
}

float	absf(float num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

t_vec	raycasting(t_state *state, t_vec dir)
{
	t_vec	plr;
	t_vec	map_check;
	t_vec	plane;
	t_vec	unit_step;
	t_vec	step;
	t_vec	ray_lend;
	t_vec	intersection;
	int		foundWall;
	float	dist;
	float	max_dist;


	plr = vec_new(state->pl->x / state->pl->size, state->pl->y / state->pl->size);
	unit_step = vec_new(absf(1.0f / dir.x), absf(1.0f / dir.y));
	map_check.x = (int)plr.x;
	map_check.y = (int)plr.y;
	if (dir.x < 0)
	{
		step.x = -1.0f;
		ray_lend.x = (plr.x - map_check.x) * unit_step.x;
	}
	else
	{
		step.x = 1.0f;
		ray_lend.x = (map_check.x + 1 - plr.x) * unit_step.x;
	}
	if (dir.y < 0)
	{
		step.y = -1.0f;
		ray_lend.y = (plr.y - map_check.y) * unit_step.y;
	}
	else
	{
		step.y = 1.0f;
		ray_lend.y = (map_check.y + 1 - plr.y) * unit_step.y;
	}
	foundWall = 0;
	max_dist = 50000.0f;
	dist = 0.0f;
	while (!foundWall && dist < max_dist)
	{
		if (ray_lend.x < ray_lend.y)
		{
			map_check.x += step.x;
			dist = ray_lend.x;
			ray_lend.x += unit_step.x;
		}
		else
		{
			map_check.y += step.y;
			dist = ray_lend.y;
			ray_lend.y += unit_step.y;
		}
		if (map_check.x >= 0 && map_check.y >= 0 && \
		map_check.x < state->map->width && map_check.y < state->map->height)
		{
			if (ft_strchr(" 1", state->map->map[(int)map_check.y][(int)map_check.x]))
				foundWall = 1;
		}
	}
	intersection.x = 0;
	intersection.y = 0;
	intersection.color = 0xFF0000;
	if (foundWall == 1)
	{
		// printf("player is on x %f y %f\n", plr.x, plr.y);
		//printf((("dir x %f y %f len %f\n", dir.x, dir.y, vec_len(dir));
		intersection = find_intersection(plr, dir, dist);
		intersection.color = 0xFF0000;
		intersection.dist = dist;
		// printf("ray hit the wall in x %f y %f\n", intersection.x, intersection.y);
		// printf("len from plr to wall %f\n", vec_dist(plr, intersection));
		// printf("len from plr to wall %f\n", dist);

		// intersection.x = RES_X / intersection.x;
		// intersection.y = RES_Y / intersection.y;
	}
	return (intersection);
}

t_vec	**raycasting_fov(t_state *state)
{
	t_vec	**rays;
	t_vec	*ray;
	int		i;
	float	steps;

	rays = (t_vec **)malloc(sizeof(t_vec *) * RES_X);
	steps = (float)FOV / RES_X;
	float start = - FOV / 2;
	i = 0;
	while (i < RES_X)
	{
		t_vec dir = vec_rot(vec_new(-1.0f, 0.0f), state->pl->a + start);
		ray = malloc(sizeof(t_vec));
		*ray = raycasting(state, dir);
		rays[i] = ray;
		rays[i]->angle = state->pl->a + start;
		start += steps;
		i++;
	}
	return (rays);
}
