#include "./render.h"

void	draw_player(t_state *state, t_img *img)
{
	t_rec	rec;
	float size = RES_X / state->map->width;

	rec.x = state->pl->y * size;
	rec.y = state->pl->x * size;
	rec.width = rec.x + size;
	rec.height = rec.y + size;
	rec.color = COL_YELLOW;
	draw_rec(img, &rec);
}

draw_rays(t_state *state, t_vec **rays, t_img *img)
{
	float size = RES_X / state->map->width;

	for (int i = 0; rays[i]; ++i) {
		rays[i]->x = rays[i]->x * size;
		rays[i]->y = rays[i]->y * size;
		if (i <= FOV / 2 + 5 && i >= FOV / 2 - 5)
			rays[i]->color = COL_RED;
		else
			rays[i]->color = COL_YELLOW;
		put_pixel(img, rays[i]->x, rays[i]->y, rays[i]->color);
	}
}

// void draw_walls(t_state *state, t_vec *rays, t_img *img)
// {
// 	float	scalar_prod;
// 	int		i;

// 	i = -1;
// 	while (rays[++i])
// 	{
// 		scalar_prod = vec_scal_prod(state->pl->a, *rays[i]);

// 	}
// }

void	draw_some_shit(t_state *state, t_img *img)
{
	t_rec	rec;
	t_vec **rays = raycasting_fov(state);
	float size = RES_X / state->map->width;

	draw_map(state, img);
	draw_player(state, img);
	draw_rays(state, rays, img);
}

void	render(t_state *state)
{
	size_t	i;
	size_t	j;
	t_img	*img;

	img = new_img(state->mlx);
	i = 0;
	draw_some_shit(state, img);
	mlx_put_image_to_window(state->mlx, state->win, img->img_ptr, 0, 0);
	free_img(state->mlx, img);
	return ;
}
