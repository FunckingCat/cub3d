#include "./render.h"

void	draw_some_shit(t_state *state, t_img *img)
{
	t_rec	rec;
	float size = RES_X / state->map->width;

	draw_map(state, img);
	t_vec **rays = raycasting_fov(state);
	rec.x = state->pl->y * size;
	rec.y = state->pl->x * size;
	rec.width = rec.x + size;
	rec.height = rec.y + size;
	rec.color = COL_YELLOW;
	draw_rec(img, &rec);
	for (int i = 0; rays[i]; ++i) {
		rec.x = rays[i]->x * (size);
		rec.y = rays[i]->y * (size);
		rec.width = rec.x + size / 2;
		rec.height = rec.y + size / 2;
		rec.color = COL_RED;
		draw_rec(img, &rec);
		// put_pixel(img, rays[i]->x * size, rays[i]->y * size, COL_RED);
	}
}

void	render(t_state *state)
{
	size_t	i;
	size_t	j;
	t_img	*img;

	img = new_img(state->mlx);
	i = 0;
	// while (i < RES_X)
	// {
	// 	j = 0;
	// 	while (j < RES_Y)
	// 	{
	// 		put_pixel(img, i, j, COL_BLUE);
	// 		j++;
	// 	}
	// 	i++;
	// }
	draw_some_shit(state, img);
	mlx_put_image_to_window(state->mlx, state->win, img->img_ptr, 0, 0);
	free_img(state->mlx, img);
	return ;
}
