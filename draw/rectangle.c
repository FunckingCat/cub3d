/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:01:36 by rusty             #+#    #+#             */
/*   Updated: 2022/02/14 02:02:02 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_rec(t_img *img, t_rec *rec)
{
	for (int i = rec->x; i < rec->width; i++)
	{
		for (int j = rec->y; j < rec->height; j++)
		{
			put_pixel(img, i, j, rec->color);
		}
	}
}
