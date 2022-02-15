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
# include "../draw/draw.h"

# define COL_WHITE	0xffffff
# define COL_BLACK	0x000000
# define COL_DGRAY	0x303030
# define COL_LGRAY	0x919191
# define COL_RED	0xFF7E7E
# define COL_YELLOW	0xFFF700
# define COL_BLUE	0x000d85
# define COL_GREEN	0x2d752e

struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
};

// typedef struct	s_rec
// {
// 	int	x;
// 	int	y;
// 	int	width;
// 	int	height;
// 	int	color;
// }	t_rec;

void	render(t_state *state);

t_img	*new_img(void *mlx);
void	free_img(void *mlx, t_img *img);
void	put_pixel(t_img *img, int x, int y, int color);

#endif
