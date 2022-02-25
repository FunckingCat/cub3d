#include "./render.h"

void	render_column(t_state *st, t_img *img, t_vec *ray, int col)
{
	float	half_heigh;
	t_vec	start;
	t_vec	end;
	float	line_ratio;
	float	wall_heigh;

	wall_heigh = RES_Y / (2 * cosf(st->pl.angle - ray->angle) * tan(VFOV) * ray->dist);
	start.color = st->map->ceiling_color;
	end.color = st->map->floor_col;
	start.x = col;
	end.x = col;
	start.y = (RES_Y / 2) + wall_heigh;
	end.y = (RES_Y / 2) - wall_heigh;
	//printf("col %d --- dist %f; half_heigh %f; height %f\n", col, ray->dist, half_heigh, wall_heigh * 2);
	//printf("%d column\tS x(%f) y(%f)\tE x(%f) y(%f)\n", col, start.x, start.y, end.x, end.y);
	put_line(img, start, end);
}

void	put_floor_and_celing(t_state *st, t_img *img)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < RES_Y / 2)
	{
		i = 0;
		while (i < RES_X)
			put_pixel(img, i++, j, st->map->ceiling_color);
		j++;
	}
	j = RES_Y / 2;
	while (j < RES_Y)
	{
		i = 0;
		while (i < RES_X)
			put_pixel(img, i++, j, st->map->floor_col);
		j++;
	}
}

void	render_walls(t_state *st, t_vec **rays, t_img *img)
{
	float	scalar_prod;
	int		i;

	i = 0;
	put_floor_and_celing(st, img);
	while (i < RES_X)
	{
		render_column(st, img, rays[i], i);
		i++;
	}
}
