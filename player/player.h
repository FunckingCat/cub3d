#ifndef PLAYER_H
# define PLAYER_H

# include "../libft/libft.h"
# include "../map/map.h"
# include "../constants.h"
# include "../vector/vector.h"

t_vec		*new_player(t_map *map);
void		print_player(t_vec *pl);

#endif