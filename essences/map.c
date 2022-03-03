#include "./map.h"

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
	size_t i;

	printf("-------  MAP  --------\n");
	printf("NO\t%s\n",map->no_path);
	printf("SO\t%s\n",map->so_path);
	printf("WE\t%s\n",map->we_path);
	printf("EA\t%s\n",map->ea_path);
	printf("FLOOR\t%d\n",map->floor_col);
	printf("CEILING\t%d\n",map->ceiling_color);
	printf("WIDTH\t%ld\n",map->width);
	printf("HEIGHT\t%ld\n",map->height);
	i = -1;
	while (++i < map->height)
		printf("%s\n", map->map[i]);
	printf("------------------------------\n");
}