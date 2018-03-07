/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:34:13 by dsheptun          #+#    #+#             */
/*   Updated: 2018/03/07 19:07:16 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	ft_fabs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static float	ft_fmax(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void			draw_line(t_point po, t_point pz, t_mapinfo *m)
{
	float	step;
	float	t;
	int		col;
	t_point	sum;

	t = 0;
	if (po.col == 1 && pz.col == 1)
		col = 0x00FFFFF;
	else
		col = 0xFFFAFA;
	step = (float)(1 / (ft_fmax(ft_fabs(po.x - pz.x), ft_fabs(po.z - pz.z)) *
				2));
	while (t <= 1)
	{
		sum.x = po.x + t * (pz.x - po.x);
		sum.y = po.y + t * (pz.y - po.y);
		sum.z = po.z + t * (pz.z - po.z);
		mlx_pixel_put(m->mlx, m->win, sum.x, sum.z, col);
		t = t + step;
	}
}

void			rot_point(t_mapinfo *map, t_mapinfo *copy)
{
	rot_x(map->rot_x, copy);
	rot_y(map->rot_y, copy);
	rot_z(map->rot_z, copy);
}
