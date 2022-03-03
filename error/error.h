/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:12:16 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/03 17:12:17 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../libft/libft.h"

void	put_error_exit(char *msg);
void	put_ext_error_exit(char *obj, char *msg);

// VALIDATION / PARSING ERRORS
# define ERR_ARGS_M		"too many arguments"
# define ERR_ARGS_F		"no config file provided"
# define ERR_FILE		"no such file or directory"
# define ERR_READ		"error while reading file"
# define ERR_CONFIG		"config file not valid"
# define ERR_UNEXP_NEAR	"config file: unexpected value near"
# define ERR_CONF_UNEXP	"config file: unexpected value"
# define ERR_CONF_TAB	"conif file can't contain tabs"
# define ERR_MAP_FORMAT	"config file must be *.cub"
# define ERR_TEXTURE	"wall texture not defined"
# define ERR_TEXTURE_NF	"wall texture not found"
# define ERR_XPM_FORMAT	"config file: the wall texture should be *.xpm"
# define ERR_COL_FORMAT	"color format error (0-255,0-255,0-255 reqired)"
# define ERR_NO_F_COL	"floor color not set"
# define ERR_NO_C_COL	"ceiling color not set"
# define ERR_F_COL		"floor color is in wrong format"
# define ERR_C_COL		"ceiling color is in wrong format"
# define ERR_NO_MAP		"there is no map in the config file"
# define ERR_MAP		"map not valid"
# define ERR_MAP_FORB	"the map contains forbidden symbols"
# define ERR_NO_PLAYER	"there no player on the map"
# define ERR_NOT_ONE_P	"there is more than one player on the map"
# define ERR_NOT_CLOSED	"map must be surrounded by walls"
# define ERR		""

#endif