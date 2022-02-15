/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:17:50 by rusty             #+#    #+#             */
/*   Updated: 2022/02/15 03:48:18 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_rot(t_vec v, float alfa)
{
	t_vec	ret;

	alfa = alfa * 3.14f / 180.0f;
	ret.x = v.x * cos(alfa) + v.y * -sin(alfa);
	ret.y = v.x * sin(alfa) + v.y * cos(alfa);
	return (ret);
}
