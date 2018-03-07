/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:05:01 by dsheptin          #+#    #+#             */
/*   Updated: 2018/03/07 19:33:53 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(float angle, t_mapinfo *map)
{
	float	y1;
	float	z1;
	int		i;
	int		j;
	float	pi;

	pi = 3.1415;
	angle = angle * (pi / 180);
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			z1 = map->points[j][i].z * cos(angle) - map->points[j][i].y
				* sin(angle);
			y1 = map->points[j][i].y * cos(angle) + map->points[j][i].z
				* sin(angle);
			map->points[j][i].y = y1;
			map->points[j][i].z = z1;
			i++;
		}
		j++;
	}
}

void	rot_y(float angle, t_mapinfo *map)
{
	float	x1;
	float	z1;
	int		i;
	int		j;
	float	pi;

	pi = 3.1415;
	angle = angle * (pi / 180);
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			x1 = map->points[j][i].z * cos(angle) + map->points[j][i].x
				* sin(angle);
			z1 = map->points[j][i].x * cos(angle) - map->points[j][i].z
				* sin(angle);
			map->points[j][i].x = x1;
			map->points[j][i].z = z1;
			i++;
		}
		j++;
	}
}

void	rot_z(float angle, t_mapinfo *map)
{
	float	x1;
	float	y1;
	int		i;
	int		j;
	float	pi;

	pi = 3.1415;
	angle = angle * (pi / 180);
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			x1 = map->points[j][i].y * cos(angle) - map->points[j][i].x
				* sin(angle);
			y1 = map->points[j][i].y * sin(angle) + map->points[j][i].x
				* cos(angle);
			map->points[j][i].x = x1;
			map->points[j][i].y = y1;
			i++;
		}
		j++;
	}
}
