#include "./render.h"

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
	draw_map(state, img);
	putline_bresenham(img, vec_new(state->pl->y, state->pl->x), raycasting(state));
	mlx_put_image_to_window(state->mlx, state->win, img->img_ptr, 0, 0);
	free_img(state->mlx, img);
	return ;
}
