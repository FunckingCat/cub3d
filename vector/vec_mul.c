/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:28:43 by rusty             #+#    #+#             */
/*   Updated: 2022/02/13 23:30:36 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_mul(t_vec v, float mul)
{
	t_vec	ret;

	ret.x = v.x * mul;
	ret.y = v.y * mul;
	return (ret);
}
