#ifndef STATE_H
# define STATE_H

#include "../mlx/mlx.h"
#include "../map/map.h"
#include "../player/player.h"

typedef struct s_state
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*pl;
}	t_state;

#endif