#include "./player.h"

t_player	*new_player(t_map *map)
{
	t_player	*pl;
	size_t		i;
	size_t		j;

	pl = ft_malloc(sizeof(t_player));
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr("SNWE", map->map[i][j]))
			{
				pl->y = i;
				pl->x = j;
				if (map->map[i][j] == 'E')
					pl->a = 0;
				if (map->map[i][j] == 'S')
					pl->a = PI / 2;
				if (map->map[i][j] == 'W')
					pl->a = PI;
				if (map->map[i][j] == 'N')
					pl->a = (3 * PI) / 2;
				map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return(pl);
}

void	print_player(t_player *pl)
{
	printf("-------  PLAYER  --------\n");
	printf("player x\t%f\n", pl->x);
	printf("player y\t%f\n", pl->y);
	printf("player ang\t%f\n", pl->a);
	printf("--------------------------\n");
}