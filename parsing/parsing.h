#ifndef PARSING_H
# define PARSING_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "../constants.h"
# include "../error/error.h"
# include "../map/map.h"
# include "../render/render.h"

void	validate(int ac ,char **av);
int		split_size(char **arr);
t_map	*parse_map(char	*path);
void	check_map(t_map *map);

# define C_CUB	".cub"
# define C_XPM	".xpm"
# define C_NO	"NO"
# define C_SO	"SO"
# define C_WE	"WE"
# define C_EA	"EA"
# define C_F	"F"
# define C_C	"C"
# define MAP_SYMBOLS " 10NSEW"

#endif