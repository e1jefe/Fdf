//
// Created by Dmytro SHEPTUN on 2/27/18.
//

#include "fdf.h"

void	rotate_x(float angle, t_mapinfo *map)
{
	float	y1;
	float	z1;
	int		u;
	int		v;

	angle = angle * 0.01745329252;
	v = 0;
	while (v < map->height)
	{
		u = 0;
		while (u < map->width)
		{
			z1 = map->points[v][u].z * cos(angle) - map->points[v][u].y
													* sin(angle);
			y1 = map->points[v][u].y * cos(angle) + map->points[v][u].z
													* sin(angle);
			map->points[v][u].y = y1;
			map->points[v][u].z = z1;
			u++;
		}
		v++;
	}
}

void	rotate_y(float angle, t_mapinfo *map)
{
	float	x1;
	float	z1;
	int		u;
	int		v;

	v = 0;
	angle = angle * 0.01745329252;
	while (v < map->height)
	{
		u = 0;
		while (u < map->width)
		{
			x1 = map->points[v][u].z * cos(angle) + map->points[v][u].x
													* sin(angle);
			z1 = map->points[v][u].x * cos(angle) - map->points[v][u].z
													* sin(angle);
			map->points[v][u].x = x1;
			map->points[v][u].z = z1;
			u++;
		}
		v++;
	}
}

void	rotate_z(float angle, t_mapinfo *map)
{
	float	x1;
	float	y1;
	int		u;
	int		v;

	v = 0;
	angle = angle * 0.01745329252;
	while (v < map->height)
	{
		u = 0;
		while (u < map->width)
		{
			x1 = map->points[v][u].y * cos(angle) - map->points[v][u].x
													* sin(angle);
			y1 = map->points[v][u].y * sin(angle) + map->points[v][u].x
													* cos(angle);
			map->points[v][u].x = x1;
			map->points[v][u].y = y1;
			u++;
		}
		v++;
	}
}