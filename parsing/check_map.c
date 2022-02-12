#include "parsing.h"

void	check_border(t_map *map)
{
	size_t i;

	i = 0;
	while(i < map->width)
	{
		if (!ft_strchr(" 1", map->map[0][i]) ||
			!ft_strchr(" 1", map->map[map->height - 1][i]))
			put_ext_error_exit(ERR_MAP, ERR_NOT_CLOSED);
		i++;
	}
	i = 0;
	while(i < map->height)
	{
		if (!ft_strchr(" 1", map->map[i][0]) ||
			!ft_strchr(" 1", map->map[i][map->width - 1]))
			put_ext_error_exit(ERR_MAP, ERR_NOT_CLOSED);
		i++;
	}
}

void	check_spaces_tb(t_map *map)
{
	size_t i;

	i = 1;
	while (i < map->width)
	{
		
	}
}

void	check_map(t_map *map)
{
	if (!map->no_path || !map->so_path || 
		!map->we_path || !map->ea_path)
		put_ext_error_exit(ERR_CONFIG, ERR_TEXTURE);
	if (ft_strcmp(C_XPM, ft_strrchr(map->no_path, '.')) ||
		ft_strcmp(C_XPM, ft_strrchr(map->so_path, '.')) ||
		ft_strcmp(C_XPM, ft_strrchr(map->we_path, '.')) ||
		ft_strcmp(C_XPM, ft_strrchr(map->ea_path, '.')))
		put_error_exit(ERR_XPM_FORMAT);
	check_border(map);
	check_spaces(map);
}