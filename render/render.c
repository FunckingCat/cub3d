#include "./render.h"

void	throw_ray(t_state *st, double angle, t_img *img)
{
	t_ray	*ray;
	ray = new_ray(st, angle);
	float x1, y1, x2,y2;
	int i, L, xstart, ystart, xend, yend;
	float dX, dY, x[100000], y[100000];

	x1 = ray->st_x;
	y1 = ray->st_y;
	x2 = ray->end_x;
	y2 = ray->end_y;
	xstart = roundf(x1);
	ystart = roundf(y1);
	xend = roundf(x2);
	yend = roundf(y2);
	L = fmax(abs(xend-xstart), abs(yend-ystart));
	printf("L %d\n", L);
	dX = (x2-x1) / L;
	dY = (y2-y1) / L;
	i = 0;
	x[i] = x1;
	y[i] = y1;
	i++;
	while (i < L)
	{
		x[i] = x[i-1] + dX;
		y[i] = y[i-1] + dY;
		i++;
	}
	x[i] = x2;
	y[i] = y2;
	i = 0;
	while (i <= L)
	{
		put_pixel (img, roundf(x[i]), roundf(y[i]), COL_YELLOW);
		i++;
	}
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
			if (i == rec->x || j == rec->y)
				put_pixel(img, i, j, COL_DGRAY);
			else if (i == rec->width - 1 || j == rec->height - 1)
				put_pixel(img, i, j, COL_DGRAY);
			else
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