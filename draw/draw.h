/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:52:21 by rusty             #+#    #+#             */
/*   Updated: 2022/02/15 23:08:21 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../state/state.h"
# include "../vector/vector.h"
# include "../mlx/mlx.h"
# include "../render/render.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_rec
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rec;

/* LINE  */

void	init_utils_points(t_point *dpoint, t_point *incs, t_vec start, \
t_vec end);
double	percent(int start, int end, int current);
int		get_light(int start, int end, double percentage);
int		get_color(t_point current, t_vec start, t_vec end, t_point delta);
void	init_point_bresenham(t_point *point, t_vec cell);
void	bresenham_1(t_img *img, t_vec start, t_vec end);
void	bresenham_2(t_img *img, t_vec start, t_vec end);
void	putline_bresenham(t_img *img, t_vec start, t_vec end);

/*rectangle*/
void	put_rec(t_img *img, t_rec *rec);

/*map*/
void	draw_map(t_state *state, t_img *img);

#endif