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

void	vec_print(t_vec v, char *str)
{
	printf("------- %s -------\n", str);
	printf("--> vec.x\t%f\n", v.x);
	printf("--> vec.y\t%f\n", v.y);
	printf("--> vec.angle\t%f\n", v.angle);
	printf("--> vec.dist\t%f\n", v.dist);
	printf("---------------------\n");
}