#include "./render.h"

void	render(t_state *state)
{
	t_img	*frame;
	t_vec	**rays = raycasting_fov(state);
	int		i;
	
	frame = new_img(state->mlx);
	render_walls(state, rays, frame);
	render_minimap(state, frame, rays);
	mlx_put_image_to_window(state->mlx, state->win, frame->img_ptr, 0, 0);
	free_img(state->mlx, frame);
	i = 0;
	while (i < RES_X)
		free(rays[i++]);
	free(rays);
	return ;
}
