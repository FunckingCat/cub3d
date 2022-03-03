/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:07:24 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/03 17:19:16 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include "../libft/libft.h"
# include "../libmlx/mlx.h"
# include "../constants.h"
# include "../state/state.h"
# include "../vector/vector.h"

# define FOV	1.2
# define VFOV	0.523614

typedef struct s_img	t_img;

struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		width;
	int		height;
};

struct	s_ray
{
	t_vec	start_point;
	t_vec	map_check_digit;
	t_vec	unit_step;
	t_vec	stap_digit;
};

typedef struct s_rec
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rec;

typedef struct s_column
{
	t_img	*texture;
	float	wall_height;
	int		top;
	int		bot;
	int		col;
}	t_column;

void	render(t_state *state);

t_img	*new_img(void *mlx);
t_img	*new_img_xpm(void *mlx, char *path);
void	free_img(void *mlx, t_img *img);
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);

t_vec	raycasting(t_state *state, t_vec dir);
t_vec	**raycasting_fov(t_state *state);

void	render_minimap(t_state *state, t_img *img, t_vec **rays);

void	render_walls(t_state *st, t_vec **rays, t_img *img);

# define COL_WHITE	0xffffff
# define COL_BLACK	0x000000
# define COL_DGRAY	0x303030
# define COL_LGRAY	0x919191
# define COL_RED	0xFF7E7E
# define COL_YELLOW	0xFFF700
# define COL_BLUE	0x000d85
# define COL_GREEN	0x2d752e

# define TYPE_NO 1
# define TYPE_SO 2
# define TYPE_WE 3
# define TYPE_EA 4

#endif
