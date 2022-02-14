#include "./render.h"

t_ray	*new_ray(t_state *state, double angle)
{
	t_ray	*ray;

	ray = ft_malloc(sizeof(t_ray));
	ray->size = (double)RES_X / (double)state->map->width;
	ray->st_x = state->pl->x * ray->size + ray->size / 2;
	ray->st_y = state->pl->y * ray->size + ray->size / 2;
	ray->length = sqrt(pow(state->map->width * ray->size, 2) + \
		pow(state->map->height * ray->size, 2));
	ray->dx = ray->length * cos(angle);
	ray->dy = ray->length * sin(angle);
	ray->end_x = ray->st_x + ray->dx;
	ray->end_y = ray->st_y + ray->dy;
	ray->angle = angle;
	ray->scale_x = sqrt(1 + pow((ray->dy, ray->dx), 2));
	ray->scale_y = sqrt(1 + pow((ray->dx, ray->dy), 2));
	ray->dir_x = 1;
	if (ray->st_x - ray->end_x < 0)
		ray->dir_x = -1;
	ray->dir_y = 1;
	if (ray->st_y - ray->end_y < 0)
		ray->dir_y = -1;
	ray->steps_x = 0;
	ray->steps_y = 0;
	return (ray);
}

void	print_ray(t_ray *ray)
{
	printf("LEN\t%f\n", ray->length);
	printf("ANG\t%f\n", ray->angle);
	printf("SIZE\t%f\n", ray->size);
	printf("START X\t%f\n", ray->st_x);
	printf("START Y\t%f\n", ray->st_y);
	printf("END X\t%f\n", ray->end_x);
	printf("END Y\t%f\n", ray->end_y);
	printf("DX\t%f\n", ray->dx);
	printf("DY\t%f\n", ray->dy);
	printf("SCALE X\t%f\n", ray->scale_x);
	printf("SCALE Y\t%f\n", ray->scale_y);
	printf("DIR X\t%f\n", ray->dir_x);
	printf("DIR Y\t%f\n", ray->dir_y);
}