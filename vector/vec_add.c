/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:15:06 by rusty             #+#    #+#             */
/*   Updated: 2022/02/21 17:30:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"vector.h"

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	ret.angle = v1.angle;
	ret.dist = vec_len(ret);
	return (ret);
}
