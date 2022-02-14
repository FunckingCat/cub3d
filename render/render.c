#include "./render.h"

t_vec	*cast_ray(t_state *st, float an, t_img *img)
{
	float	x;
	float	y;
	int		tx;
	int		ty;
	t_vec	*vec;

	vec = ft_malloc(sizeof(t_vec));
	for (float c = 0; ; c+=1)
	{
		y = st->pl->y + c * sin(an);
		x = st->pl->x + c * cos(an);
		tx = (int)floor(x / st->pl->size);
		ty = (int)floor(y / st->pl->size);
		if (tx < 0 || tx > st->map->width || ty < 0 || ty > st->map->height)
			continue;
		if (st->map->map[ty][tx] == '1')
			break;
		put_pixel(img, (int)x, (int)y, COL_YELLOW);
	}
	vec->x = x;
	vec->y = y;
	return (vec);
}

void	render_rays(t_state *st, t_img *img)
{
	float x;
	float y;

	for (int i = 0; i < FOV; i++)
		cast_ray(st, st->pl->a + (i * DEG), img);
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