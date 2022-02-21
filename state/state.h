#ifndef STATE_H
# define STATE_H

#include "../mlx/mlx.h"
#include "../map/map.h"
#include "../player/player.h"

typedef struct s_state
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_vec	*pl;
	float	size;
}	t_state;

#endif