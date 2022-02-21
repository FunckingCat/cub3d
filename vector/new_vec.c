#include "./vector.h"

t_vec	new_vec(float dist, float ang)
{
	t_vec	res;

	res.dist = dist;
	res.angle = ang;
	res.x = dist * cosf(ang);
	res.y = dist * sinf(ang);
	return (res);
}