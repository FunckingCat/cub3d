#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../error/error.h"

typedef struct s_tex
{
	size_t	width;
	size_t	height;
	size_t	colors;
	size_t	chpp;
	char	**chars;
	int		*ints;
	int		**d;
}	t_tex;

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_tex	no_tex;
	t_tex	so_tex;
	t_tex	we_tex;
	t_tex	ea_tex;
	int		floor_col;
	int		ceiling_color;
	size_t	width;
	size_t	height;
	char	**map;
}	t_map;

int		split_size(char **arr);
t_map	*new_map(void);
void	print_map(t_map *map);

#endif