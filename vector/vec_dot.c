/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:47:52 by rusty             #+#    #+#             */
/*   Updated: 2022/02/13 22:13:47 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v2.y * v2.y);
}
