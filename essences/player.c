#include "./player.h"

t_vec	new_player(t_map *map)
{
	t_vec	pl;
	float	size;
	size_t	i;
	size_t	j;

	size = (float)RES_X / (float)map->width;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr("SNWE", map->map[i][j]))
			{
				pl.y = i * size + size / 2;
				pl.x = j * size + size / 2;
				if (map->map[i][j] == 'E')
					pl.angle = 0;
				if (map->map[i][j] == 'S')
					pl.angle = (3 * PI) / 2;
				if (map->map[i][j] == 'W')
					pl.angle = PI;
				if (map->map[i][j] == 'N')
					pl.angle = PI / 2;
				map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	pl.dist = vec_len(pl);
	return(pl);
}
