#include "./render.h"

void	render_column(t_state *st, t_img *img, t_vec *ray, int col)
{
	float	half_heigh;
	int		top;
	int		bot;
	int		i;
	float	wall_heigh;

	wall_heigh = RES_Y / (2 * cosf(st->pl.angle - ray->angle) * tan(VFOV) * ray->dist);
	//printf("col %d --- dist %f; height %f\n", col, ray->dist, wall_heigh * 2);
	top = (int)((RES_Y / 2) - wall_heigh);
	bot = (int)((RES_Y / 2) + wall_heigh);
	if (top < 0)
		top = 0;
	if (bot > RES_Y)
		bot = RES_Y;
	//printf("COL %d TOP %d BOT %d\n", col, top, bot);
	i = 0;
	while (i < top)
		put_pixel(img, col, i++, st->map->ceiling_color);
	while (i < bot)
		put_pixel(img, col, i++, COL_LGRAY);
	while (i < RES_Y)
		put_pixel(img, col, i++, st->map->floor_col);
}

void	render_walls(t_state *st, t_vec **rays, t_img *img)
{
	size_t	i;

	i = 0;
	while (i < RES_X)
	{
		render_column(st, img, rays[i], i);
		i++;
	}
}
