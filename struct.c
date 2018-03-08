/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:34:13 by dsheptun          #+#    #+#             */
/*   Updated: 2018/03/08 14:53:43 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		numbers(char *str)
{
	int		i;
	int		cnt;
	char	**z;

	z = ft_strsplit(str, ' ');
	i = 0;
	cnt = 0;
	while (z[i])
	{
		free(z[i]);
		cnt++;
		i++;
	}
	free(z);
	return (cnt);
}

void			ft_map(t_mapinfo *map, t_point ***cloud, int i)
{
	int		j;
	char	**split_line;
	t_point	**new;

	map->width = numbers(map->map[i--]);
	new = (t_point**)malloc(sizeof(t_point*) * map->height);
	while (++i < map->height)
	{
		if (map->width != numbers(map->map[i]))
		{
			ft_putstr("Invalid file");
			exit(0);
		}
		new[i] = (t_point*)malloc(sizeof(t_point) * map->width);
		j = -1;
		split_line = ft_strsplit(map->map[i], ' ');
		while (++j < map->width)
		{
			new[i][j] = new_point(j, ft_atoi(split_line[j]), i);
			free(split_line[j]);
		}
		free(split_line);
	}
	*cloud = new;
}

t_point			**ft_mapcopy(t_mapinfo *map)
{
	int		i;
	int		j;
	t_point	**new;

	i = 0;
	new = (t_point**)malloc(sizeof(t_point*) * map->height);
	while (i < map->height)
	{
		new[i] = (t_point*)malloc(sizeof(t_point) * map->width);
		j = 0;
		while (j < map->width)
		{
			new[i][j] = map->points[i][j];
			j++;
		}
		i++;
	}
	return (new);
}

void			free_map(t_mapinfo map)
{
	int		i;

	i = 0;
	while (i < map.height)
	{
		free(map.points[i]);
		i++;
	}
	free(map.points);
	map.points = NULL;
}

void			cr_map(t_mapinfo *map, char **argv, int error)
{
	if (error != 2)
	{
		map->scale_x = ft_atoi(argv[2]);
		map->scale_y = ft_atoi(argv[3]);
	}
	else
	{
		map->scale_x = 20;
		map->scale_y = 20;
	}
	map->stock_x = map->scale_x;
	map->stock_y = map->scale_y;
	map->points_num = map->height * map->width;
}
