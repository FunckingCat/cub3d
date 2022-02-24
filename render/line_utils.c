#include "./render.h"

void	init_utils_points(t_point *dpoint, t_point *incs, t_vec start, \
t_vec end)
{
	if (end.x >= start.x)
	{
		dpoint->x = (int)(end.x - start.x);
		incs->x = 1;
	}
	else
	{
		dpoint->x = (int)(start.x - end.x);
		incs->x = -1;
	}
	if (end.y >= start.y)
	{
		dpoint->y = (int)(end.y - start.y);
		incs->y = 1;
	}
	else
	{
		dpoint->y = (int)(start.y - end.y);
		incs->y = -1;
	}
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0f);
	else
		return (placement / distance);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point current, t_vec start, t_vec end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, \
	(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, \
	(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	init_point_bresenham(t_point *point, t_vec cell)
{
	point->x = (int)cell.x;
	point->y = (int)cell.y;
	point->color = cell.color;
}
