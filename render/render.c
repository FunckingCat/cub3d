#include "./render.h"

void	throw_ray(t_state *st, double angle, t_img *img)
{
	t_ray	*ray;
	int		wall_found;
	double	x;
	double	y;

	ray = new_ray(st, angle);
	print_map(st->map);
	print_player(st->pl);
	print_ray(ray);
	ray->len_x = ray->size * ray->sc_x * ray->scale_x;
	ray->len_y = ray->size * ray->sc_y * ray->scale_y;
	print_ray(ray);
	if (ray->len_x < ray->len_y)
	{
		x = ray->st_x + (ray->sc_x * ray->size) * cos(ray->angle);
		y = ray->st_y + (ray->sc_x * ray->size) * sin(ray->angle);
	}
	else
	{
		x = ray->st_x + (ray->sc_y * ray->size) * cos(ray->angle);
		y = ray->st_y + (ray->sc_y * ray->size) * sin(ray->angle);
	}
	printf("X %d Y %d\n", (int)x, (int)y);
	put_pixel(img, (int)x, (int)y, COL_YELLOW);
	// wall_found = 0;
	// while ((ray->len_x < ray->length || ray->len_y < ray->length) && !wall_found)
	// {
	// 	if (ray->len_x > ray->len_y)
	// 		ray->sc_y += 1;
	// 	else
	// 		ray->sc_x += 1;
	// 	ray->len_x = ray->size * ray->sc_x * ray->scale_x;
	// 	ray->len_y = ray->size * ray->sc_y * ray->scale_y;
	// 	print_ray(ray);
	// 	if (ray->len_x < ray->len_y)
	// 	{
	// 		a = tan(ray->angle);
	// 		x = ray->st_x + ray->sc_x * ray->size;
	// 		y = ray->st_y + a * (ray->sc_x * ray->size);
	// 	}
	// 	else
	// 	{
	// 		a = cos(ray->angle) / sin(ray->angle);
	// 		y = ray->st_y + ray->sc_y * ray->size;
	// 		x = ray->st_x + a * (ray->sc_y * ray->size);
	// 	}
	// 	printf("X %d Y %d ang %f\n", (int)x, (int)y, a);
	// 	put_pixel(img, (int)x, (int)y, COL_RED);
	// 	break;
	// }
}

void	render_rays(t_state *state, t_img *img)
{
	throw_ray(state, state->pl->a, img);
}

void	render_player(t_state *state, t_img *img)
{
	size_t	size = (RES_X / state->map->width);
	size_t	pl_size = size / 3;
	int		dx;
	int		dy;

	for (size_t i = state->pl->x - pl_size; i < state->pl->x + pl_size; i++)
	{
		for (size_t j = state->pl->y - pl_size; j < state->pl->y + pl_size; j++)
		{
			dx = i - state->pl->x;
			dy = j - state->pl->y;
			if (dx * dx + dy * dy < pl_size * pl_size)
				put_pixel(img, i, j, COL_GREEN);
		}
	}
	put_pixel(img, state->pl->x, state->pl->y, COL_RED);
}

void	draw_rec(t_img *img, t_rec *rec)
{
	for (int i = rec->x; i < rec->width; i++)
	{
		for (int j = rec->y; j < rec->height; j++)
		{
			put_pixel(img, i, j, rec->color);
		}
	}
}

void	render_map(t_state *state, t_img *img)
{
	t_rec	rec;

	for (size_t i = 0; i < state->map->height; i++)
	{
		for (size_t j = 0; j < state->map->width; j++)
		{
			rec.x = (int)(j * state->pl->size);
			rec.y = (int)(i * state->pl->size);
			rec.width = (int)(rec.x + state->pl->size);
			rec.height = (int)(rec.y + state->pl->size);
			if (ft_strchr(" 1", state->map->map[i][j]))
				rec.color = COL_DGRAY;
			else
				rec.color = COL_LGRAY;
			draw_rec(img, &rec);
		}
	}
}

void	render(t_state *state)
{
	t_img	*frame;
	
	frame = new_img(state->mlx);
	render_map(state, frame);
	render_player(state, frame);
	render_rays(state, frame);
	mlx_put_image_to_window(state->mlx, state->win, frame->img_ptr, 0, 0);
	free_img(state->mlx, frame);
	return ;
}