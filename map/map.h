#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "../libft/libft.h"
#include "../error/error.h"

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
int		char_to_hex(char **arr);
int		split_size(char **arr);
t_map	*new_map(void);

#endif