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
#define WIN_W 1280
#define WIN_H 720

typedef struct		s_cord
{
	double				x;
	double				y;
	double				z;
	uint32_t			col;
}					t_cord;

typedef struct			s_lists
{
char **points;
struct 					s_lists *next;
}						t_lists;

typedef struct		s_mapinfo
{
	t_lists *start;
	t_cord	*uk;
	int		lines;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		width2;
	int		height2;
}					t_mapinfo;

//typedef double t_vec __attribute__((vector_size(sizeof(double)*3)));
static int     ft_keys(int key, void *zlx);
int	count_columns(t_mapinfo *map, char *line);
void			read_map(char *filename, t_mapinfo *map);
void	ft_print_map(t_mapinfo *uk);
int	count_lines(t_mapinfo *map);

#endif