/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:10:49 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/14 15:50:58 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "../constants.h"
# include "../error/error.h"
# include "../state/state.h"
# include "../render/render.h"

void	validate(int ac, char **av);
int		split_size(char **arr);
t_map	*parse_map(char	*path);
void	check_map(t_map *map);
int		char_to_hex(char **arr);
void	check_texture_path(t_map *map);

# define C_CUB	".cub"
# define C_XPM	".xpm"
# define C_NO	"NO"
# define C_SO	"SO"
# define C_WE	"WE"
# define C_EA	"EA"
# define C_F	"F"
# define C_C	"C"
# define MAP_SYMBOLS	" 10NSEW"

#endif