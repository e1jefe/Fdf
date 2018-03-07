/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:34:13 by dsheptun          #+#    #+#             */
/*   Updated: 2018/03/07 19:22:53 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_rot(int key, t_mapinfo *map)
{
	if (key == 12)
		map->rot_y += ANG;
	if (key == 14)
		map->rot_y -= ANG;
	if (key == 13)
		map->rot_x += ANG;
	if (key == 1)
		map->rot_x -= ANG;
	if (key == 0)
		map->rot_z += ANG;
	if (key == 2)
		map->rot_z -= ANG;
}

static void	key_scale(int key, t_mapinfo *map)
{
	if (key == 34)
		map->scale_x -= 2;
	if (key == 38)
		map->scale_x += 2;
	if (key == 37)
		map->scale_y += 2;
	if (key == 40)
		map->scale_y -= 2;
}

static void	key_res(t_mapinfo *map)
{
	map->scale_x = map->stock_x;
	map->scale_y = map->stock_y;
	map->rot_y = 111;
	map->rot_z = -126;
	map->rot_x = 246;
}

static void	key_move(int key, t_mapinfo *map)
{
	if (key == 123)
		map->scale_pv -= 50;
	if (key == 124)
		map->scale_pv += 50;
	if (key == 125)
		map->scale_pg += 50;
	if (key == 126)
		map->scale_pg -= 50;
}

int			key_hook(int key, t_mapinfo *map)
{
	t_mapinfo copy;

	copy = *map;
	copy.points = ft_mapcopy(map);
	if (key == 53 || key == 15)
		key == 53 ? exit(0) : key_res(map);
	if (key >= 0 && key <= 14)
		key_rot(key, map);
	if (key >= 32 && key <= 40)
		key_scale(key, map);
	if (key >= 123 && key <= 126)
		key_move(key, map);
	mlx_clear_window(0, map->win);
	scale_points(&copy, copy.scale_x, copy.scale_y);
	rot_point(map, &copy);
	centrmap(&copy);
	move_points(&copy);
	draw_map(copy);
	free_map(copy);
	return (0);
}
