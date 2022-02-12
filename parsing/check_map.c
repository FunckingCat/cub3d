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

void	check_spaces(char **map, size_t i, size_t j)
{
	if (map[i-1][j-1] == ' ' ||
		map[i+1][j+1] == ' ' ||
		map[i+1][j-1] == ' ' ||
		map[i-1][j+1] == ' ' ||
		map[i][j-1] == ' ' ||
		map[i][j+1] == ' ' ||
		map[i-1][j] == ' ' ||
		map[i+1][j] == ' ')
		put_ext_error_exit(ERR_MAP, ERR_NOT_CLOSED);
}

void	check_zeros(t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr("0NSEW", map->map[i][j]))
				check_spaces(map->map, i, j);
			j++;
		}
		i++;
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
	check_zeros(map);
}