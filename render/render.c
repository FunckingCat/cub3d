/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:06:46 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/03 17:07:10 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

void	render(t_state *state)
{
	t_img	*frame;
	t_vec	**rays;
	int		i;

	frame = new_img(state->mlx);
	rays = raycasting_fov(state);
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
