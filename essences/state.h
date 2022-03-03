#ifndef STATE_H
# define STATE_H

#include "../mlx/mlx.h"
#include "./map.h"
#include "./player.h"

typedef struct s_state
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_vec	pl;
	float	size;
}	t_state;

#endif