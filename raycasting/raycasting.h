/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:21:32 by rusty             #+#    #+#             */
/*   Updated: 2022/03/03 15:25:47 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../vector/vector.h"
# include "../essences/state.h"
# include "../libft/libft.h"

# include "../constants.h"

t_vec	raycasting(t_state *state, t_vec dir);
t_vec	**raycasting_fov(t_state *state);

struct	s_ray
{
	t_vec	start_point;
	t_vec	map_check_digit;
	t_vec	unit_step;
	t_vec	stap_digit;
};

#endif