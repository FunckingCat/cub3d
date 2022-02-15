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

// void	init_ray(t_state *state, t_vec dir)
// {

// }

t_vec	raycasting(t_state *state, t_vec dir)
{
	t_vec	plr;
	t_vec	map_check;
	t_vec	plane;
	t_vec	unit_step;
	t_vec	step;
	t_vec	ray_lend;

	int		foundWall;
	float	dist;
	float	max_dist;

	t_vec	intersection;

	plr = vec_new(state->pl->y, state->pl->x);
/*
**				a to radians or sm like that or a affects on dir
*/
	// dir = vec_rot(vec_new(-1.0f, 0.0f), state->pl->a * 3.14f / 180.0f); // later add 
	// dir = vec_new(1.0f, 0.0f); // later add 
	// vec_norm(&dir);
	// plane = vec_new(0.0f, 0.66f);
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
	max_dist = 500.0f;
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
			// ft_strchr(" 1", state->map->map[i][j]
			if (ft_strchr(" 1", state->map->map[(int)map_check.y][(int)map_check.x]))
				foundWall = 1;
			// if (foundWall == 1)
				//printf(("ray found wall in y %d x %d\n", (int)map_check.y, (int)map_check.x);
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
	int		i;
	int		j;
	t_vec	**rays;

	int		steps;

	steps = FOV / RES_X;
	j = 0;
	rays = (t_vec **)ft_malloc(sizeof(t_vec *) * FOV);
	i = -FOV / 2;
	while (++i < (FOV / 2) - 1)
	{
		// t_vec plane = vec_new(0.0f, i / 100.0f);
		// t_vec dir = vec_rot(vec_add(vec_new(-1.0f, 0.0f), plane), state->pl->a * 3.14f / 180.0f);
		
		t_vec dir = vec_rot(vec_new(-1.0f, 0.0f), (state->pl->a + (float)i));
		t_vec *ray = ft_malloc(sizeof(t_vec));
		*ray = raycasting(state, dir);
		ray->angle = state->pl->a + (float)i;
		rays[j++] = ray;
	}
	rays[j] = NULL;
	return (rays);
}
