#include "./map.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	char_to_hex(char **arr)
{
	if (split_size(arr) != 3)
		put_error_exit(ERR_COL_FORMAT);
	if (!ft_isstrdigit(arr[0]) ||
		!ft_isstrdigit(arr[1]) ||
		!ft_isstrdigit(arr[2]))
		put_error_exit(ERR_COL_FORMAT);
	if (ft_atoi(arr[0]) > 255 ||
		ft_atoi(arr[1]) > 255 ||
		ft_atoi(arr[2]) > 255)
		put_error_exit(ERR_COL_FORMAT);
	return (rgb_to_hex(ft_atoi(arr[0]), 
			ft_atoi(arr[1]),
			ft_atoi(arr[2])));
}

t_map	*new_map(void)
{
	t_map	*map;

	map = ft_malloc(sizeof(t_map));
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->floor_col = 0;
	map->ceiling_color = 0;
	return (map);
}

void	print_map(t_map *map)
{
	printf("-------  MAP  --------\n");
	printf("NO\t%s\n",map->no_path);
	printf("SO\t%s\n",map->so_path);
	printf("WE\t%s\n",map->we_path);
	printf("EA\t%s\n",map->ea_path);
	printf("FLOOR\t%d\n",map->floor_col);
	printf("CEIL\t%d\n",map->ceiling_color);
	printf("----------------------\n");
}