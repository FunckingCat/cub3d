#include "./parsing.h"

void	parse_meta(t_tex *res, int fd)
{
	char	**split;

	while(ft_strcmp(CHARS_HEADER, gnl(fd)))
		;
	split = ft_split(ft_strtrim(gnl(fd), " ,\""), ' ');
	res->width = ft_atoi(split[0]);
	res->height = ft_atoi(split[1]);
	res->colors = ft_atoi(split[2]);
	res->chpp = ft_atoi(split[3]);
}

void	parse_colors(t_tex *res, int fd)
{
	char	*line;
	char	**split;
	int		i;

	i = 0;
	res->chars = ft_malloc(sizeof(char *) * (res->colors + 1));
	res->ints = ft_malloc(sizeof(int) * res->colors);
	line = gnl(fd);
	while(ft_strcmp(PIXELS_HEADER, line))
	{
		split = ft_split(ft_strtrim(line, "\","), 'c');
		res->chars[i] = ft_malloc(sizeof(char) * res->chpp + 1);
		ft_memmove(res->chars[i], split[0], res->chpp);
		res->ints[i] = hex_to_int(ft_strtrim(split[1], " #"));
		i++;
		line = gnl(fd);
	}
}

int	find_color(t_tex *res, char *chr)
{
	size_t	i;

	i = 0;
	while (i < res->colors)
	{
		if (!ft_memcmp(res->chars[i], chr, res->chpp))
			return (res->ints[i]);
		i++;
	}
	return (0);
}

void	parse_grid(t_tex *res, int fd)
{
	size_t	i;
	size_t	j;
	char	*line;

	res->d = ft_malloc(sizeof(int *) * res->height);
	i = 0;
	while (i < res->width)
	{
		res->d[i] = ft_malloc(sizeof(int) * res->width);
		line = ft_strtrim(gnl(fd), "\",");
		j = 0;
		while (j < 1)
		{
			res->d[i][j] = find_color(res, line);
			line += res->chpp;
			j++;
		}
		i++;
	}
}

t_tex	parse_xpm_texture(char *path)
{
	t_tex	res;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		put_ext_error_exit(path, ERR_TEXTURE_NF);
	parse_meta(&res, fd);
	parse_colors(&res, fd);
	parse_grid(&res, fd);
	return (res);
}
