#include "raycasting.h"

t_vec	find_intersection(t_vec plr, t_vec dir, float dist)
{
	t_vec ret;
	t_vec ray;
	float tmp;

	

	ray = vec_mul(dir, dist);
	printf("test %f %f\n", ray.x, ray.y);
	ret = vec_add(plr, ray);
	printf("test2 %f %f\n", ret.x, ret.y);
	// tmp = ret.x;
	// ret.x = ret.y;
	// ret.y = tmp;
	return (ret);
}

t_vec	raycasting(t_state *state, t_vec dir)
{
	t_vec	plr;
	t_vec	map_check;
	// t_vec	dir;
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
	vec_norm(&dir);
	plane = vec_new(0.0f, 0.66f);
	unit_step = vec_new(abs(1.0f / dir.x), abs(1.0f / dir.y));
	map_check = plr;
	if (dir.x < 0)
	{
		step.x = -1;
		ray_lend.x = (plr.x - map_check.x) * unit_step.x;
	}
	else
	{
		step.x = 1;
		ray_lend.x = (map_check.x + 1 - plr.x) * unit_step.x;
	}
	if (dir.y < 0)
	{
		step.y = -1;
		ray_lend.y = (plr.y - map_check.y) * unit_step.y;
	}
	else
	{
		step.y = 1;
		ray_lend.y = (map_check.y + 1 - plr.y) * unit_step.y;
	}
	foundWall = 0;
	max_dist = 100.0f;
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
			if (foundWall == 1)
				printf("ray found wall in y %d x %d\n", (int)map_check.y, (int)map_check.x);
		}
	}
	intersection.x = 0;
	intersection.y = 0;
	intersection.color = 0xFF0000;
	if (foundWall == 1)
	{
		printf("player is on x %f y %f\n", plr.x, plr.y);
		printf("dir x %f y %f len %f\n", dir.x, dir.y, vec_len(dir));
		intersection = find_intersection(plr, dir, dist);
		intersection.color = 0xFF0000;
		printf("ray hit the wall in x %f y %f\n len from plr to wall %f\n", intersection.x, intersection.y, vec_len(intersection));

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

	j = 0;
	rays = (t_vec **)ft_malloc(sizeof(t_vec *) * 67 * 2);
	i = -65;
	while (++i < 65)
	{
		t_vec plane = vec_new(0.0f, i / 100.0f);
		t_vec dir = vec_rot(vec_add(vec_new(-1.0f, 0.0f), plane), state->pl->a * 3.14f / 180.0f);
		t_vec *ray = ft_malloc(sizeof(t_vec));
		*ray = raycasting(state, dir);
		rays[j++] = ray;
	}
	rays[130] = NULL;
	return (rays);
}
