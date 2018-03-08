/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:50:13 by dsheptun          #+#    #+#             */
/*   Updated: 2018/03/08 12:59:53 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		new_point(int x, int y, int z)
{
	t_point	new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = z;
	if (new_point.y > 0)
		new_point.col = 1;
	else
		new_point.col = 0;
	return (new_point);
}

void		move_points(t_mapinfo *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x += map->scale_pv;
			map->points[i][j].z += map->scale_pg;
			j++;
		}
		i++;
	}
}

void		scale_points(t_mapinfo *map, int scale_x, int scale_y)
{
	int i;
	int	k;

	i = 0;
	while (i < map->height)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x *= scale_x;
			map->points[i][k].y *= scale_y;
			map->points[i][k].z *= scale_x;
			k++;
		}
		i++;
	}
}

void		centrmap(t_mapinfo *map)
{
	int	i;
	int	k;
	int	offset_x;
	int	offset_y;

	i = 0;
	offset_x = map->points[map->height / 2][map->width / 2].x;
	offset_y = map->points[map->height / 2][map->width / 2].z;
	while (i < map->height)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x -= offset_x;
			map->points[i][k].x += WIN_W / 2;
			map->points[i][k].z -= offset_y;
			map->points[i][k].z += WIN_H / 2;
			k++;
		}
		i++;
	}
}
