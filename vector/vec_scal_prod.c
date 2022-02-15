/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scal_prod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 03:51:29 by rusty             #+#    #+#             */
/*   Updated: 2022/02/15 06:55:34 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static float	absf(float num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

static float	to_rad(float deg)
{
	return (deg * 3.14f / 180.0f);
}

float	vec_scal_prod(float angle, t_vec projected)
{
	float	alfa;

	alfa =  to_rad(angle) - to_rad(projected.angle);
	return (projected.dist * cosf(alfa));
}
