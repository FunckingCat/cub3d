/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scal_prod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 03:51:29 by rusty             #+#    #+#             */
/*   Updated: 2022/03/03 16:23:22 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	to_rad(float deg)
{
	return (deg * 3.14f / 180.0f);
}

float	vec_scal_prod(float angle, t_vec projected)
{
	float	alfa;

	alfa = to_rad(angle) - to_rad(projected.angle);
	return (projected.dist * cosf(alfa));
}
