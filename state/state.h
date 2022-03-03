/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:02:31 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/03 17:02:32 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libmlx/mlx.h"
# include "../constants.h"
# include "../error/error.h"
# include "../vector/vector.h"

typedef struct s_img	t_img;

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
	int		floor_col;
	int		ceiling_color;
	size_t	width;
	size_t	height;
	char	**map;
}	t_map;

typedef struct s_state
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_vec	pl;
	float	size;
}	t_state;

t_map		*new_map(void);
t_vec		new_player(t_map *map);

#endif