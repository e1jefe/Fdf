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

# include <sys/types.h> 
# include <sys/stat.h> 

# include <mlx.h>
# include "libft/libft.h"

#define KEY_ESC 53
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define WIN_W 1500
#define WIN_H 1000
#define SCALE 25

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
	int		scale_x;
	int		scale_y;
	float	rot_x;
	float	rot_y;
	float	rot_z;
}					t_mapinfo;

//typedef double t_vec __attribute__((vector_size(sizeof(double)*3)));
static int		ft_keys(int key, void *zlx);
int				count_columns(t_mapinfo *map, char *line);
void			read_map(char *filename, t_mapinfo *map);
void			ft_print_map(t_mapinfo *uk);
t_cord			new_point(double x, double y, double z);
void			init_point(char **arr, int i, t_mapinfo **map);
void			ft_centr_cord(t_mapinfo *map);
void		scale_points(t_mapinfo *map, int scale_x, int scale_y);
#endif