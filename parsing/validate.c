/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:10:58 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/03 17:11:11 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

int	validate_conf_str(char *str)
{
	char	**split;

	if (!str)
		return (-1);
	if (ft_strlen(ft_strtrim(str, " ")) == 0)
		return (0);
	if (ft_strchr(str, '\t'))
		put_ext_error_exit(ERR_CONFIG, ERR_CONF_TAB);
	split = ft_split(str, ' ');
	if (split_size(split) != 2)
		put_ext_error_exit(ERR_CONF_UNEXP, str);
	if (ft_strcmp(split[0], C_NO)
		&& ft_strcmp(split[0], C_SO)
		&& ft_strcmp(split[0], C_WE)
		&& ft_strcmp(split[0], C_EA)
		&& ft_strcmp(split[0], C_F)
		&& ft_strcmp(split[0], C_C))
		put_ext_error_exit(ERR_CONF_UNEXP, str);
	if (split_size(ft_split(split[1], ',')) == 3)
		return (1);
	if (ft_strcmp(C_XPM, ft_strrchr(split[1], '.')))
		put_ext_error_exit(ERR_XPM_FORMAT, str);
	return (1);
}

void	validate_conf(int fd)
{
	int	status;
	int	count;

	count = 0;
	while (count < 6)
	{
		status = validate_conf_str(gnl(fd));
		if (status == -1)
			put_error_exit(ERR_CONFIG);
		count += status;
	}
}

void	validate_map(int fd)
{
	char	*str;
	char	*tmp;

	str = gnl(fd);
	while (str && ft_strlen(ft_strtrim(str, " ")) == 0)
		str = gnl(fd);
	while (str && ft_strlen(ft_strtrim(str, " ")) != 0)
	{
		tmp = ft_strdup(str);
		while (*str)
		{
			if (!ft_strchr(MAP_SYMBOLS, *str))
				put_ext_error_exit(ERR_UNEXP_NEAR, tmp);
			str++;
		}
		str = gnl(fd);
	}
	str = gnl(fd);
	while (str)
	{
		if (str && ft_strlen(ft_strtrim(str, " ")) != 0)
			put_ext_error_exit(ERR_CONF_UNEXP, str);
		str = gnl(fd);
	}
}

void	validate(int ac, char **av)
{
	int	conf;

	if (ac == 1)
		put_error_exit(ERR_ARGS_F);
	if (ac > 2)
		put_error_exit(ERR_ARGS_M);
	if (ft_strcmp(C_CUB, ft_strrchr(av[1], '.')))
		put_ext_error_exit(ERR_CONFIG, ERR_MAP_FORMAT);
	conf = open(av[1], O_RDONLY);
	if (conf == -1)
		put_ext_error_exit(av[1], ERR_FILE);
	validate_conf(conf);
	validate_map(conf);
	close(conf);
}
