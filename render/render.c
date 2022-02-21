#include "./render.h"

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

	i = 0;
	while (i < RES_X)
	{
		// abs angle ??? 
		// #fix should fix fisheye ray dist or something in vec scal prod goes wrong
		//scalar_prod = vec_scal_prod(state->pl->a, *(rays[i]));
		//draw_scaled_wall(img, scalar_prod, i);
		
		// fish eye
		draw_scaled_wall(img, rays[i]->dist, i);
		i++;
	}
}

void	render_rays(t_state *state, t_img *img, t_vec **rays)
{
	float size = RES_X / state->map->width;

	for (int i = 0; i < RES_X - 1; i++) {
		rays[i]->x = rays[i]->x * size;
		rays[i]->y = rays[i]->y * size;
		put_pixel(img, rays[i]->x, rays[i]->y, COL_YELLOW);
	}
}

void	render_player(t_state *state, t_img *img)
{
	size_t	size = (RES_X / state->map->width);
	size_t	pl_size = size / 3;
	int		dx;
	int		dy;

	for (size_t i = state->pl.x - pl_size; i < state->pl.x + pl_size; i++)
	{
		for (size_t j = state->pl.y - pl_size; j < state->pl.y + pl_size; j++)
		{
			dx = i - state->pl.x;
			dy = j - state->pl.y;
			if (dx * dx + dy * dy < pl_size * pl_size)
				put_pixel(img, i, j, COL_GREEN);
		}
	}
	put_pixel(img, state->pl.x, state->pl.y, COL_RED);
}

void	draw_rec(t_img *img, t_rec *rec)
{
	for (int i = rec->x; i < rec->width; i++)
	{
		for (int j = rec->y; j < rec->height; j++)
			put_pixel(img, i, j, rec->color);
	}
}

void	render_map(t_state *state, t_img *img)
{
	t_rec	rec;

	for (size_t i = 0; i < state->map->height; i++)
	{
		for (size_t j = 0; j < state->map->width; j++)
		{
			rec.x = (int)(j * state->size);
			rec.y = (int)(i * state->size);
			rec.width = (int)(rec.x + state->size);
			rec.height = (int)(rec.y + state->size);
			rec.color = COL_LGRAY;
			if (!ft_strchr(" 1", state->map->map[i][j]))
				draw_rec(img, &rec);
		}
	}
}

void	render(t_state *state)
{
	t_img	*frame;
	t_vec	**rays = raycasting_fov(state);
	int		i;
	
	frame = new_img(state->mlx);
	render_map(state, frame);
	render_player(state, frame);
	render_rays(state, frame, rays);
	//draw_walls(state, rays, frame);
	mlx_put_image_to_window(state->mlx, state->win, frame->img_ptr, 0, 0);
	free_img(state->mlx, frame);
	i = 0;
	while (i < RES_X)
		free(rays[i++]);
	free(rays);
	return ;
}
