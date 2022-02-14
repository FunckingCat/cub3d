/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:21:32 by rusty             #+#    #+#             */
/*   Updated: 2022/02/14 06:19:26 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../vector/vector.h"
# include "../state/state.h"
# include "../map/map.h"
# include "../libft/libft.h"

# include "../constants.h"

t_vec	raycasting(t_state *state, t_vec dir);
t_vec	**raycasting_fov(t_state *state);
#endif