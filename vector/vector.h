/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:12:04 by rusty             #+#    #+#             */
/*   Updated: 2022/03/03 15:50:00 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_vec	t_vec;

struct s_vec
{
	float	x;
	float	y;
	int		color;
	float	angle;
	float	dist;
};

void	vec_norm(t_vec *v);
float	vec_dot(t_vec v1, t_vec v2);
float	vec_len(t_vec v);
float	vec_dist(t_vec v1, t_vec v2);
float	vec_scal_prod(float angle, t_vec projected);
t_vec	vec_add(t_vec v1, t_vec v2);
t_vec	vec_mul(t_vec v, float mul);
t_vec	vec_new(float x, float y);
t_vec	vec_rot(t_vec v, float alfa);
t_vec	vec_sub(t_vec v1, t_vec v2);

#endif