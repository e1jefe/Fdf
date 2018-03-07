/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:18:13 by dsheptun          #+#    #+#             */
/*   Updated: 2018/03/07 19:09:07 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <libc.h>
#include <math.h>
#include "./libft/libft.h"
#include "./minilibx/mlx.h"
#define WIN_W 1500
#define WIN_H 1000
#define ANG 7

typedef struct		s_point
{
	int	x;
	int	y;
	int	z;
	int	col;
}					t_point;

typedef struct		s_mapinfo
{
	char	**map;
	int		height;
	int		width;
	int		points_num;
	void	*mlx;
	void	*win;
	t_point	**points;
	int		scale_x;
	int		scale_y;
	int 	scale_pg;
	int 	scale_pv;
	float	rot_x;
	float	rot_y;
	float	rot_z;
	int		stock_x;
	int		stock_y;
}					t_mapinfo;

t_point				new_point(int x, int y, int z);
t_mapinfo			reader_map(char *filename);
t_point				**ft_mapcopy(t_mapinfo *map);
void				scale_points(t_mapinfo *map, int scale_x, int scale_y);
void				rot_x(float angle, t_mapinfo *map);
void				rot_y(float angle, t_mapinfo *map);
void				rot_z(float angle, t_mapinfo *map);
void				ft_map(t_mapinfo *map, t_point ***clou, int i);
void				init_map(t_mapinfo *mapinfo);
int					check_error(int argc, char **argv);
void				draw_line(t_point po, t_point pz, t_mapinfo *m);
void				ft_movemap(t_mapinfo *map, int offset_x, int offset_y);
void				centrmap(t_mapinfo *map);
void				draw_map(t_mapinfo map);
int					key_hook(int key, t_mapinfo *map);
void				free_map(t_mapinfo map);
void				free_file(t_mapinfo map);
void				move_points(t_mapinfo *map);
void				rot_point(t_mapinfo *map, t_mapinfo *copy);
void				cr_map(t_mapinfo *map, char **argv, int error);

#endif
