#include "./parsing.h"

void	set_map_prop(t_map *map, char **arr)
{
	if (!ft_strcmp(C_NO, arr[0]) && map->no_path == NULL)
		map->no_path = arr[1];
	else if (!ft_strcmp(C_SO, arr[0]) && map->so_path == NULL)
		map->so_path = arr[1];
	else if (!ft_strcmp(C_WE, arr[0]) && map->we_path == NULL)
		map->we_path = arr[1];
	else if (!ft_strcmp(C_EA, arr[0]) && map->ea_path == NULL)
		map->ea_path = arr[1];
	else if (!ft_strcmp(C_F, arr[0]) && map->floor_col == 0)
		map->floor_col = char_to_hex(ft_split(arr[1], ','));
	else if (!ft_strcmp(C_C, arr[0]) && map->ceiling_color == 0)
		map->ceiling_color = char_to_hex(ft_split(arr[1], ','));
	else
		put_ext_error_exit(ERR_CONF_UNEXP, arr[0]);
}

void	read_props(t_map *map, int fd)
{
	int		count;
	char	*str;

	count = 0;
	while (count < 6)
	{
		str = gnl(fd);
		while (ft_strlen(ft_strtrim(str, " ")) == 0)
			str = gnl(fd);
		set_map_prop(map, ft_split(str, ' '));
		count++;
	}
}

void	read_map(t_map *map, int fd)
{
	t_list	*list;
	char	*str;
	int		i;
	size_t	len;

	str = gnl(fd);
	while (ft_strlen(ft_strtrim(str, " ")) == 0)
		str = gnl(fd);
	len = 0;
	list = ft_lstnew(NULL);
	while (str && ft_strlen(ft_strtrim(str, " ")) != 0)
	{
		if (len < ft_strlen(str))
			len = ft_strlen(str);
		ft_lstadd_back(&list, ft_lstnew(str));
		str = gnl(fd);
	}
	map->height = ft_lstsize(list) - 1;
	map->width = len;
	map->map = ft_malloc(sizeof(char *) * ft_lstsize(list));
	i = 0;
	while (i < map->height)
	{
		list = list->next;
		map->map[i] = ft_malloc(sizeof(char) * (len + 1));
		ft_memset(map->map[i], ' ', len);
		ft_memmove(map->map[i], list->content, ft_strlen(list->content));
		printf("map: '%s'\n", map->map[i]);
		i++;
	}
}

t_map	*parse_map(char *path)
{
	t_map	*map;
	int		fd;

	map = new_map();
	fd = open(path, O_RDONLY);
	if (fd == -1)
		put_ext_error_exit(path, ERR_FILE);
	read_props(map, fd);
	read_map(map, fd);
	return (map);
}
