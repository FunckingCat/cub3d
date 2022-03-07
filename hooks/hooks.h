/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:11:24 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/07 12:28:26 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "../libmlx/mlx.h"
# include "../libft/libft.h"
# include "../state/state.h"
# include "../constants.h"
# include "../error/error.h"
# include "../render/render.h"
# include "../vector/vector.h"

void	set_hooks(t_state *state);

# define MAC_A_KEY		0
# define MAC_S_KEY		1
# define MAC_D_KEY		2
# define MAC_W_KEY		13
# define MAC_Q_KEY		123
# define MAC_E_KEY		124
# define MAC_ESC		53

# define KEYEXIT	17
# define KEYPRESS	2
# define W_KEY		119
# define A_KEY		97
# define S_KEY		115
# define D_KEY		100
# define Q_KEY		113
# define E_KEY		101
# define ESC		65307

#endif