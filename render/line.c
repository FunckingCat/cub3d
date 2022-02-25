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

void	init_point_bresenham(t_point *point, t_vec cell)
{
	point->x = (int)cell.x;
	point->y = (int)cell.y;
	point->color = cell.color;
}

void	bresenham_1(t_img *img, t_vec start, t_vec end)
{
	t_point	point;
	t_point	dpoint;
	t_point	incs;
	int		balance;
	int		color;

	init_utils_points(&dpoint, &incs, start, end);
	init_point_bresenham(&point, start);
	dpoint.y <<= 1;
	balance = dpoint.y - dpoint.x;
	dpoint.x <<= 1;
	while (point.x != (int)end.x)
	{
		color = COL_LGRAY;
		put_pixel(img, point.x, point.y, color);
		if (balance >= 0)
		{
			point.y += incs.y;
			balance -= dpoint.x;
		}
		balance += dpoint.y;
		point.x += incs.x;
	}
	color = COL_LGRAY;
	put_pixel(img, point.x, point.y, color);
}

void	bresenham_2(t_img *img, t_vec start, t_vec end)
{
	t_point	point;
	t_point	dpoint;
	t_point	incs;
	int		balance;
	int		color;

	init_utils_points(&dpoint, &incs, start, end);
	init_point_bresenham(&point, start);
	dpoint.x <<= 1;
	balance = dpoint.x - dpoint.y;
	dpoint.y <<= 1;
	while (point.y != (int)end.y)
	{
		color = COL_LGRAY;
		put_pixel(img, point.x, point.y, color);
		if (balance >= 0)
		{
			point.x += incs.x;
			balance -= dpoint.y;
		}
		balance += dpoint.x;
		point.y += incs.y;
	}
	color = COL_LGRAY;
	put_pixel(img, point.x, point.y, color);
}

void	put_line(t_img *img, t_vec start, t_vec end)
{
	t_point	dpoint;
	t_point	incs;

	init_utils_points(&dpoint, &incs, start, end);
	if (dpoint.x >= dpoint.y)
	{
		bresenham_1(img, start, end);
	}
	else
	{
		bresenham_2(img, start, end);
	}
}
