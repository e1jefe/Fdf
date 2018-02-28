/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:39:34 by dsheptun          #+#    #+#             */
/*   Updated: 2018/02/06 12:39:35 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h> 
# include <sys/stat.h> 

# include <mlx.h>
# include "libft/libft.h"

#define WIN_W 1500
#define WIN_H 1000
#define SCALE 20
#define ANGL 5

typedef struct		s_cord
{
	double				x;
	double				y;
	double				z;
	uint32_t			col;
}					t_cord;

typedef struct			s_lists
{
char **arr;
struct 					s_lists *next;
}						t_lists;

typedef struct		s_mapinfo
{
	t_lists *start;
	t_cord **points;
	t_cord **base;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		width2;
	double	scale_x;
	double	scale_y;
	double  scale_plus;
	float	rot_x;
	float	rot_y;
	float	rot_z;
	double centr_x;
	double centr_y;
}					t_mapinfo;

//typedef double t_vec __attribute__((vector_size(sizeof(double)*3)));
static int		ft_keys(int key, t_mapinfo *map);
int				count_columns(t_mapinfo *map, char *line);
void			read_map(char *filename, t_mapinfo *map);
void			ft_print_map(t_mapinfo *uk);
t_cord			new_point(double x, double y, double z);
void			init_point(char **arr, int i, t_mapinfo **map);
void			ft_centr_cord(t_mapinfo *map);
void			ft_draw(t_mapinfo *map);
void			move_points(t_mapinfo *map, double scale_x, double scale_y);
void			scale_points(t_mapinfo *map, double scale_plus);
void			rotate_x(float angle, t_mapinfo *map);
void			rotate_y(float angle, t_mapinfo *map);
void			rotate_z(float angle, t_mapinfo *map);
void			ft_current_centr_cord(t_mapinfo *map);
#endif