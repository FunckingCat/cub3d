/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:31:57 by rusty             #+#    #+#             */
/*   Updated: 2022/02/21 16:30:06 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_map(t_state *state, t_img *img)
{
	size_t	size = RES_X / state->map->width;
	// t_img	*img = new_img(state->mlx);
	t_rec	rec;

	for (size_t i = 0; i < state->map->height; i++)
	{
		for (size_t j = 0; j < state->map->width; j++)
		{
			rec.x = j * size;
			rec.y = i * size;
			rec.width = (int)(rec.x + size);
			rec.height = (int)(rec.y + size);
			if (ft_strchr(" 1", state->map->map[i][j]))
				rec.color = COL_DGRAY;
			else if (state->pl.x == i && state->pl.y == j)
				rec.color = 0xFF0000;
			else
				rec.color = COL_LGRAY;
			put_rec(img, &rec);
		}
	}
	// mlx_put_image_to_window(state->mlx, state->win, img->img_ptr, 0, 0);
}