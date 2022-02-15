/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scal_prod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 03:51:29 by rusty             #+#    #+#             */
/*   Updated: 2022/02/15 03:59:15 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	vec_scal_prod(float angle, t_vec projected)
{
	float	alfa;

	alfa = angle - projected.angle;
	alfa = alfa * 3.14f / 180.0f;
	return (projected.dist * cos(alfa));
}
