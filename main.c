/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:18:52 by dsheptun          #+#    #+#             */
/*   Updated: 2018/03/08 14:52:13 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int			check_error(int argc, char **argv)
{
	if (argc == 2)
		return (2);
	if (argc != 4)
	{
		ft_putstr("Usage : ./fdf <filename>");
		return (-1);
	}
	else
	{
		if ((ft_atoi(argv[2]) == 0) || (ft_atoi(argv[3]) == 0))
		{
			ft_putstr("Usage : ./fdf <filename>");
			return (-1);
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_mapinfo	map;
	int			error;

	if (argc == 2)
	{
		ft_bzero(&map, sizeof(t_mapinfo));
		map = reader_map(argv[1]);
		error = (check_error(argc, argv));
		cr_map(&map, argv, error);
		ft_map(&map, &map.points, 0);
		free_file(map);
		map.mlx = mlx_init();
		map.win = mlx_new_window(map.mlx, WIN_W, WIN_H, "fdf");
		init_map(&map);
		mlx_key_hook(map.win, key_hook, &map);
		mlx_loop(map.mlx);
	}
	else
		ft_putstr("usage: ./fdf source_file\n");
	return (0);
}
