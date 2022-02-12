#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include "../mlx/mlx.h"
# include "../constants.h"
# include "../state/state.h"

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

void	render(t_state *state);

#endif
