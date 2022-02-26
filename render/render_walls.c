#include "./render.h"

void	render_column(t_state *st, t_img *img, t_vec *ray, int col)
{
	float	half_heigh;
	int		top;
	int		bot;
	float	wall_heigh;

	wall_heigh = RES_Y / (2 * cosf(st->pl.angle - ray->angle) * tan(VFOV) * ray->dist);
	//printf("col %d --- dist %f; height %f\n", col, ray->dist, wall_heigh * 2);
	top = (int)((RES_Y / 2) + wall_heigh);
	bot = (int)((RES_Y / 2) - wall_heigh);
	while (top > bot)
		put_pixel(img, col, top--, COL_LGRAY);
}

void	render_walls(t_state *st, t_vec **rays, t_img *img)
{
	size_t	i;
	size_t	j;
	size_t	half;

	j = 0;
	half = RES_Y / 2;
	while (j < half)
	{
		i = 0;
		while (i < RES_X)
		{
			put_pixel(img, i, j, st->map->ceiling_color);
			put_pixel(img, i, j + half, st->map->floor_col);
			i++;
		}
		j++;
	}
	i = 0;
	while (i < RES_X)
	{
		render_column(st, img, rays[i], i);
		i++;
	}
}
