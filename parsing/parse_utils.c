/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:10:07 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/14 15:50:46 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

int	split_size(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (i);
	while (arr[i])
		i++;
	return (i);
}

int	char_to_hex(char **arr)
{
	if (split_size(arr) != 3)
		put_error_exit(ERR_COL_FORMAT);
	if (!ft_isstrdigit(arr[0]) || \
		!ft_isstrdigit(arr[1]) || \
		!ft_isstrdigit(arr[2]))
		put_error_exit(ERR_COL_FORMAT);
	if (ft_atoi(arr[0]) > 255 || \
		ft_atoi(arr[1]) > 255 || \
		ft_atoi(arr[2]) > 255)
		put_error_exit(ERR_COL_FORMAT);
	return (1 << 24 | ft_atoi(arr[0]) << 16 | \
		ft_atoi(arr[1]) << 8 | ft_atoi(arr[2]));
}

void	check_texture_path(t_map *map)
{
	int	fd;

	fd = open(map->no_path, O_RDONLY);
	if (fd == -1)
		put_ext_error_exit(map->no_path, ERR_TEXTURE_NF);
	close(fd);
	fd = open(map->so_path, O_RDONLY);
	if (fd == -1)
		put_ext_error_exit(map->so_path, ERR_TEXTURE_NF);
	close(fd);
	fd = open(map->ea_path, O_RDONLY);
	if (fd == -1)
		put_ext_error_exit(map->ea_path, ERR_TEXTURE_NF);
	close(fd);
	fd = open(map->we_path, O_RDONLY);
	if (fd == -1)
		put_ext_error_exit(map->we_path, ERR_TEXTURE_NF);
	close(fd);
}
