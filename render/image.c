/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:03:23 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/03 17:03:24 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

t_img	*new_img(void *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img_ptr = mlx_new_image(mlx, RES_X, RES_Y);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, \
		&img->bpp, &img->size_l, &img->endian);
	return (img);
}

t_img	*new_img_xpm(void *mlx, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img_ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, \
		&img->bpp, &img->size_l, &img->endian);
	return (img);
}

void	free_img(void *mlx, t_img *img)
{
	mlx_destroy_image(mlx, img->img_ptr);
	free(img);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	if (x < RES_X && y < RES_Y && x >= 0 && y >= 0)
		img->data[y * RES_X + x] = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	if (x >= img->width || y >= img->height || x < 0 || y < 0)
		return (0);
	return (img->data[y * img->width + x]);
}
