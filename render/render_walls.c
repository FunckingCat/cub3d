#include "./render.h"

int		define_wall_type(t_vec *ray)
{
	float	diff_x;
	float	diff_y;

	ray->x = roundf(ray->x * 1000) / 1000;
	ray->y = roundf(ray->y * 1000) / 1000;
	if (ray->angle > PI * 2)
		ray->angle -= PI * 2;
	if (ray->angle < 0)
		ray->angle += PI * 2;
	diff_x = ray->x - floorf(ray->x);
	diff_y = ray->y - (float)((int)ray->y);
	//printf("X: %.10f Y: %.10f A: %f DX: %.10f DY: %.10f", ray->x, ray->y, ray->angle, diff_x, diff_y);
	if (diff_x == 0) // WE or EA
	{	//1.5707    4.7123
		if (ray->angle > PI / 2 && ray->angle < 3 * PI / 2)
			return (TYPE_WE);
		else
			return (TYPE_EA);
	}
	else if (diff_y == 0)
	{
		if (ray->angle > 0 && ray->angle <= PI)
			return (TYPE_NO);
		else
			return (TYPE_SO);
	}
}

void	render_column(t_state *st, t_img *img, t_vec *ray, int col)
{
	float	half_heigh;
	int		top;
	int		bot;
	int		i;
	float	wall_heigh;
	int		type;

	// if (col == 427)
	// {
	// 	type = define_wall_type(ray);
	// 	if (type == TYPE_NO)
	// 		printf("NO\n");
	// 	if (type == TYPE_SO)
	// 		printf("SO\n");
	// 	if (type == TYPE_EA)
	// 		printf("EA\n");
	// 	if (type == TYPE_WE)
	// 		printf("WE\n");
	// }
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
	//printf("col: %d ", col);
	type = define_wall_type(ray);
	//printf(" TYPE: %d\n", type);
	while (i < top)
		put_pixel(img, col, i++, st->map->ceiling_color);
	while (i < bot)
	{
		if (type == TYPE_NO)
			put_pixel(img, col, i++, COL_BLUE);
		else if (type == TYPE_SO)
			put_pixel(img, col, i++, COL_RED);
		else if (type == TYPE_EA)
			put_pixel(img, col, i++, COL_GREEN);
		else if (type == TYPE_WE)
			put_pixel(img, col, i++, COL_YELLOW);
	}
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
