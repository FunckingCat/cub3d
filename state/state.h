#ifndef STATE_H
# define STATE_H

typedef struct s_img t_img;

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../constants.h"
# include "../error/error.h"
# include "../vector/vector.h"

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
	int		floor_col;
	int		ceiling_color;
	size_t	width;
	size_t	height;
	char	**map;
}	t_map;

typedef struct s_state
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_vec	pl;
	float	size;
}	t_state;

int			split_size(char **arr);
t_map		*new_map(void);
t_vec		new_player(t_map *map);

#endif