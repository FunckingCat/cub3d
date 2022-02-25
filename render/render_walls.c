#include "./render.h"

void	render_column(t_state *st, t_img *img, t_vec *ray, int col)
{
	float	half_heigh;
	float	vert_fov; //then calculate hfov to vfov
	t_vec	start;
	t_vec	end;
	float	line_ratio;
	float	wall_heigh;

	//vert_fov = 36.0f;
	half_heigh = tan(VFOV) * ray->dist;
	//half_heigh = tan(vert_fov / 2 * 3.14f / 180.0f) * ray->dist;
	wall_heigh = RES_Y / (2 * cosf(st->pl.angle - ray->angle) * half_heigh);
	//printf("col %d --- dist %f; half_heigh %f; height %f\n", col, ray->dist, half_heigh, wall_heigh * 2);

	start.color = COL_BLACK;
	end.color = COL_WHITE;
	start.x = col;
	end.x = col;
	start.y = (RES_Y / 2) + wall_heigh;
	end.y = (RES_Y / 2) - wall_heigh;
	// printf("%d line x%f y%f s x%f y%f e\n", i, start.x, start.y, end.x, end.y);
	putline_bresenham(img, start, end);
}

void	render_walls(t_state *st, t_vec **rays, t_img *img)
{
	float	scalar_prod;
	int		i;

	i = 0;
	while (i < RES_X)
	{
		render_column(st, img, rays[i], i);
		i++;
	}
}