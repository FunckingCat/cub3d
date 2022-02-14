#ifndef PLAYER_H
# define PLAYER_H

# include "../libft/libft.h"
# include "../map/map.h"
# include "../constants.h"

typedef struct s_player
{
	double	x;
	double	y;
	double	a;
}	t_player;

t_player	*new_player(t_map *map);
void		print_player(t_player *pl);

#endif