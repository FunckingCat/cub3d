#include "./render.h"

void	test(t_state *st, t_img *img)
{
	for (int j = 0; j < st->map->no_tex->height; j++)
	{
		for (int i = 0; i < st->map->no_tex->width; i++)
		{
			// if (st->map->no_tex->d[i][j] == 0)
			// 	printf("%d %d\n", i, j);
			put_pixel(img, j, i, st->map->no_tex->d[i][j]);
		}
	}
}

void	render(t_state *state)
{
	t_img	*frame;
	t_vec	**rays = raycasting_fov(state);
	int		i;

	frame = new_img(state->mlx);
	render_walls(state, rays, frame);
	render_minimap(state, frame, rays);
	test(state, frame);
	mlx_put_image_to_window(state->mlx, state->win, frame->img_ptr, 0, 0);
	free_img(state->mlx, frame);
	i = 0;
	while (i < RES_X)
		free(rays[i++]);
	free(rays);
	return ;
}
