#ifndef STATE_H
# define STATE_H

#include "../mlx/mlx.h"
#include "../map/map.h"

typedef struct s_state
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_state;

#endif