#include "./render.h"

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

void	render_map(t_state *state)
{
	size_t	size = RES_X / state->map->width;
	t_img	*img = new_img(state->mlx);
	t_rec	rec;

	for (size_t i = 0; i < state->map->height; i++)
	{
		for (size_t j = 0; j < state->map->width; j++)
		{
			rec.x = j * size;
			rec.y = i * size;
			rec.width = rec.x + size;
			rec.height = rec.y + size;
			if (ft_strchr(" 1", state->map->map[i][j]))
				rec.color = COL_DGRAY;
			else
				rec.color = COL_LGRAY;
			draw_rec(img, &rec);
		}
	}
	mlx_put_image_to_window(state->mlx, state->win, img->img_ptr, 0, 0);
}

void	render(t_state *state)
{
	render_map(state);
	return ;
}