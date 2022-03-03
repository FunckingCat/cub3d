#include "./render.h"

int		define_wall_type(t_vec *ray)
{
	float	diff_x;
	float	diff_y;

	ray->x = roundf(ray->x * 10000) / 10000;
	ray->y = roundf(ray->y * 10000) / 10000;
	if (ray->angle > PI * 2)
		ray->angle -= PI * 2;
	if (ray->angle < 0)
		ray->angle += PI * 2;
	diff_x = ray->x - (float)((int)ray->x);
	diff_y = ray->y - (float)((int)ray->y);
	//printf("X: %.10f Y: %.10f A: %f DX: %.10f DY: %.10f", ray->x, ray->y, ray->angle, diff_x, diff_y);
	if (diff_x == 0)
	{
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

void	put_column(t_column *col, t_vec *ray, t_img *img)
{
	int		i;
	float		i_tex;
	float		step_tex;
	int		tex_col;

	col->wall_height = col->bot - col->top;
	step_tex = col->texture->height / col->wall_height;
	tex_col = (int)roundf(col->texture->width * (ray->x - (float)((int)ray->x) + ray->y - (float)((int)ray->y)));
	i_tex = 0;
	i = col->top;
	if (col->top < 0)
	{
		i_tex += step_tex * abs(col->top);
		i = 0;
	}
	while (i < col->bot && i < RES_Y)
	{
		put_pixel(img, col->col, i++, get_pixel(col->texture, tex_col, i_tex));
		i_tex += step_tex;
	}
}

void	render_column(t_state *st, t_img *img, t_vec *ray, int col)
{
	t_column	column;
	int			type;
	int			i;

	//printf("col: %d ", col);
	type = define_wall_type(ray);
	//printf(" TYPE: %d\n", type);
	if (type == TYPE_NO)
		column.texture = st->map->no;
	else if (type == TYPE_SO)
		column.texture = st->map->so;
	else if (type == TYPE_EA)
		column.texture = st->map->ea;
	else if (type == TYPE_WE)
		column.texture = st->map->we;
	column.wall_height = RES_Y / (2 * cosf(st->pl.angle - ray->angle) * tan(VFOV) * ray->dist);
	column.top = (int)((RES_Y / 2) - column.wall_height);
	column.bot = (int)((RES_Y / 2) + column.wall_height);
	column.col = col;
	i = 0;
	while (i < column.top)
		put_pixel(img, col, i++, st->map->ceiling_color);
	i = column.bot;
	while (i < RES_Y)
		put_pixel(img, col, i++, st->map->floor_col);
	put_column(&column, ray, img);
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
