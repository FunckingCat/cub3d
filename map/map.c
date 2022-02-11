#include "./map.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
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