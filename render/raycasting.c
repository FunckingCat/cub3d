/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 07:02:27 by rusty             #+#    #+#             */
/*   Updated: 2022/03/10 04:27:15 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float	absf(float num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	init_ray(t_state *state, t_raycast *rc, t_vec dir)
{
	rc->plr = vec_new(state->pl.x / state->size, state->pl.y / state->size);
	rc->unit_step = vec_new(absf(1.0f / dir.x), absf(1.0f / dir.y));
	rc->map_check.x = (int)rc->plr.x;
	rc->map_check.y = (int)rc->plr.y;
	if (dir.x < 0)
	{
		rc->step.x = -1.0f;
		rc->ray_lend.x = (rc->plr.x - rc->map_check.x) * rc->unit_step.x;
	}
	else
	{
		rc->step.x = 1.0f;
		rc->ray_lend.x = (rc->map_check.x + 1 - rc->plr.x) * rc->unit_step.x;
	}
	if (dir.y < 0)
	{
		rc->step.y = -1.0f;
		rc->ray_lend.y = (rc->plr.y - rc->map_check.y) * rc->unit_step.y;
	}
	else
	{
		rc->step.y = 1.0f;
		rc->ray_lend.y = (rc->map_check.y + 1 - rc->plr.y) * rc->unit_step.y;
	}
}

void	cast_ray(t_state *state, t_raycast *rc)
{
	while (!rc->found_wall && rc->dist < rc->max_dist)
	{
		if (rc->ray_lend.x < rc->ray_lend.y)
		{
			rc->map_check.x += rc->step.x;
			rc->dist = rc->ray_lend.x;
			rc->ray_lend.x += rc->unit_step.x;
		}
		else
		{
			rc->map_check.y += rc->step.y;
			rc->dist = rc->ray_lend.y;
			rc->ray_lend.y += rc->unit_step.y;
		}
		if (rc->map_check.x >= 0 && rc->map_check.y >= 0 && rc->map_check.x < \
		state->map->width && rc->map_check.y < state->map->height)
		{
			if (ft_strchr(" 1", state->map->map[(int)rc->map_check.y] \
			[(int)rc->map_check.x]))
				rc->found_wall = 1;
		}
	}
}

t_vec	raycasting(t_state *state, t_vec dir)
{
	t_raycast	rc;
	t_vec		intersection;

	ft_bzero(&rc, sizeof(t_raycast));
	ft_bzero(&intersection, sizeof(t_vec));
	rc.max_dist = 50000.0f;
	init_ray(state, &rc, dir);
	cast_ray(state, &rc);
	if (rc.found_wall == 1)
	{
		intersection = vec_add(rc.plr, vec_mul(dir, rc.dist));
		intersection.color = 0;
		intersection.dist = rc.dist;
	}
	return (intersection);
}

t_vec	**raycasting_fov(t_state *state)
{
	t_vec	**rays;
	t_vec	*ray;
	int		i;
	float	step;
	float	start;

	rays = (t_vec **)malloc(sizeof(t_vec *) * RES_X);
	step = (float)FOV / RES_X;
	start = -FOV / 2;
	i = 0;
	while (i < RES_X)
	{
		ray = malloc(sizeof(t_vec));
		*ray = raycasting(state, vec_rot(vec_new(-1.0f, 0.0f), \
		state->pl.angle + start));
		rays[i] = ray;
		rays[i]->angle = state->pl.angle + start;
		start += step;
		i++;
	}
	return (rays);
}
