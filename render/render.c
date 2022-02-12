#include "./render.h"

void	render(t_state *state)
{
	size_t	i;
	size_t	j;
	t_img	*img;

	img = new_img(state->mlx);
	i = 0;
	while (i < RES_X)
	{
		j = 0;
		while (j < RES_Y)
		{
			put_pixel(img, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(state->mlx, state->win, img->img_ptr, 0, 0);
	free_img(state->mlx, img);
	return ;
}