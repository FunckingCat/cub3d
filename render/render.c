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

void	draw_scaled_wall(t_img *img, float	dist, int i)
{
	float	half_heigh;
	float	vert_fov; //then calculate hfov to vfov
	t_vec	start;
	t_vec	end;
	float	line_ratio;
	float	wall_heigh;

	vert_fov = 36.0f;
	half_heigh = tan(vert_fov / 2 * 3.14f / 180.0f) * dist;
	// half_heigh = 1 * dist;
	line_ratio = 1 / half_heigh;
	wall_heigh = RES_Y  / 2  * line_ratio;
	// printf("%f dist wall %f line ratio\n", dist, line_ratio);
	// printf("%f wall heigh\n", wall_heigh);

	start.color = COL_BLACK;
	end.color = COL_WHITE;
	start.x = i;
	end.x = i;
	start.y = (RES_Y / 2) + wall_heigh;
	end.y = (RES_Y / 2) - wall_heigh;
	// printf("%d line x%f y%f s x%f y%f e\n", i, start.x, start.y, end.x, end.y);
	putline_bresenham(img, start, end);

}

void draw_walls(t_state *state, t_vec **rays, t_img *img)
{
	float	scalar_prod;
	int		i;

	i = -1;
	while (rays[++i] != NULL)
	{
		// abs angle ??? 
		// #fix should fix fisheye ray dist or something in vec scal prod goes wrong
		scalar_prod = vec_scal_prod(state->pl->a, *(rays[i]));
		// draw_scaled_wall(img, scalar_prod, i);
		
		// fish eye
		draw_scaled_wall(img, rays[i]->dist, i);
	}
}

void	draw_some_shit(t_state *state, t_img *img)
{
	t_rec	rec;
	t_vec **rays = raycasting_fov(state);
	float size = RES_X / state->map->width;

	// draw_map(state, img);
	// draw_player(state, img);
	// draw_rays(state, rays, img);
	draw_walls(state, rays, img);
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
