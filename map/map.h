#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_col;
	int		ceiling_color;
	size_t	width;
	size_t	height;
	char	**map;
}	t_map;

int		rgb_to_hex(int r, int g, int b);
t_map	*new_map(void);

#endif