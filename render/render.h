#ifndef RENDER_H
# define RENDER_H

typedef struct s_img t_img;

# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../constants.h"
# include "../state/state.h"
# include "../vector/vector.h"
# include "../raycasting/raycasting.h"

struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
};

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


void	render(t_state *state);

t_img	*new_img(void *mlx);
void	free_img(void *mlx, t_img *img);
void	put_pixel(t_img *img, int x, int y, int color);

void	putline_bresenham(t_img *img, t_vec start, t_vec end);
void	render_minimap(t_state *state, t_img *img, t_vec **rays);

void	init_utils_points(t_point *dpoint, t_point *incs, t_vec start, \
t_vec end);
double	percent(int start, int end, int current);
int		get_light(int start, int end, double percentage);
int		get_color(t_point current, t_vec start, t_vec end, t_point delta);
void	init_point_bresenham(t_point *point, t_vec cell);
void	bresenham_1(t_img *img, t_vec start, t_vec end);
void	bresenham_2(t_img *img, t_vec start, t_vec end);
void	putline_bresenham(t_img *img, t_vec start, t_vec end);

# define COL_WHITE	0xffffff
# define COL_BLACK	0x000000
# define COL_DGRAY	0x303030
# define COL_LGRAY	0x919191
# define COL_RED	0xFF7E7E
# define COL_YELLOW	0xFFF700
# define COL_BLUE	0x000d85
# define COL_GREEN	0x2d752e

#endif
