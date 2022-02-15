#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../constants.h"
# include "../state/state.h"
# include "../vector/vector.h"
# include "../raycasting/raycasting.h"

# define COL_WHITE	0xffffff
# define COL_BLACK	0x000000
# define COL_DGRAY	0x303030
# define COL_LGRAY	0x919191
# define COL_RED	0xFF7E7E
# define COL_YELLOW	0xFFF700
# define COL_BLUE	0x000d85
# define COL_GREEN	0x2d752e

typedef struct	s_img
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;
# include "../draw/draw.h"

typedef struct	s_rec
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rec;

typedef	struct s_ray
{
	double	length;
	double	angle;
	double	size;
	double	st_x;
	double	st_y;
	double	end_x;
	double	end_y;
	double	dx;
	double	dy;
	double	scale_x;
	double	scale_y;
	int		dir_x;
	int		dir_y;
	double	sc_x;
	double	sc_y;
	double	len_x;
	double	len_y;
}	t_ray;


void	render(t_state *state);

t_img	*new_img(void *mlx);
void	free_img(void *mlx, t_img *img);
void	put_pixel(t_img *img, int x, int y, int color);

t_ray	*new_ray(t_state *state, double angle);
void	print_ray(t_ray *ray);

#endif
