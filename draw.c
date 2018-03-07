/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:00:00 by dsheptun          #+#    #+#             */
/*   Updated: 2018/03/07 17:25:48 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_helper(t_mapinfo map)
{
	int	col;

	col = 0x00FF98FF;
	mlx_string_put(map.mlx, map.win, 4, 6, col, "Q and E for y rotation");
	mlx_string_put(map.mlx, map.win, 4, 21, col, "A and D for x rotation");
	mlx_string_put(map.mlx, map.win, 4, 36, col, "W and S for z rotation");
	mlx_string_put(map.mlx, map.win, 4, 51, col,
		"I, J, K, L for scale. Arrows for move.");
	mlx_string_put(map.mlx, map.win, 4, 65, 0xFF0000, "R to reset");
}

void		draw_map(t_mapinfo map)
{
	int		i;
	int		j;

	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if (j < map.height - 1)
				draw_line(map.points[j][i], map.points[j + 1][i], &map);
			if (i < map.width - 1)
				draw_line(map.points[j][i], map.points[j][i + 1], &map);
			i++;
		}
		j++;
	}
	draw_helper(map);
}

void		init_map(t_mapinfo *map)
{
	t_mapinfo mapcpy;

	map->scale_pv = 0;
	map->scale_pg = 0;
	map->rot_x = 245;
	map->rot_y = 115;
	map->rot_z = -125;
	mapcpy = *map;
	mapcpy.points = ft_mapcopy(map);
	scale_points(&mapcpy, map->scale_x, map->scale_y);
	rot_x(map->rot_x, &mapcpy);
	rot_y(map->rot_y, &mapcpy);
	rot_z(map->rot_z, &mapcpy);
	centrmap(&mapcpy);
	draw_map(mapcpy);
	free_map(mapcpy);
}
