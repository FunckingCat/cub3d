#include "./render.h"

t_ray	*new_ray(t_state *st, double angle)
{
	t_ray	*ray;

	ray = ft_malloc(sizeof(t_ray));
	ray->angle = angle;
	ray->size = (double)RES_X / (double)st->map->width;
	ray->st_x = st->pl->x;
	ray->st_y = st->pl->y;
	ray->length = sqrt(pow(RES_X, 2) + pow(RES_Y, 2));
	ray->dx = ray->length * cos(angle);
	ray->dy = ray->length * sin(angle);
	ray->end_x = ray->st_x + ray->dx;
	ray->end_y = ray->st_y + ray->dy;
	ray->scale_x = sqrt(1 + pow((ray->dy /ray->dx), 2));
	ray->scale_y = sqrt(1 + pow((ray->dx / ray->dy), 2));
	ray->dir_x = 1;
	if (ray->st_x - ray->end_x > 0)
		ray->dir_x = 1;
	ray->dir_y = 1;
	if (ray->st_y - ray->end_y > 0)
		ray->dir_y = 1;
	ray->sc_x = (ray->st_x - st->pl->grid_x * ray->size) / ray->size;
	ray->sc_y = (ray->st_y - st->pl->grid_y * ray->size) / ray->size;
	return (ray);
}

void	print_ray(t_ray *ray)
{
	printf("========= RAY =========\n");
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
	printf("DIR X\t%d\n", ray->dir_x);
	printf("DIR Y\t%d\n", ray->dir_y);
	printf("SC X\t%f\n", ray->sc_x);
	printf("SC Y\t%f\n", ray->sc_y);
	printf("LEN X\t%f\n", ray->len_x);
	printf("LEN Y\t%f\n", ray->len_y);
	printf("=======================\n");
}