 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:34:13 by dsheptun          #+#    #+#             */
/*   Updated: 2018/02/05 10:34:15 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int     ft_keys(int key, void *zlx)
{
    t_mapinfo *mlx;

    printf("key = %d\n", key);
    mlx = (t_mapinfo*)zlx;
    if (key == 53)
        exit(0);
    return (0);

}

t_cord		new_point(double x, double y, double z)
{
	t_cord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	if (new.z != 0)
		new.col = 0x7FFF00;
	else
		new.col = 0xFFFFFF;
	return (new);
}

t_lists *list_new(char **filename)
{

	t_lists *list_new;

	list_new = ft_memalloc(sizeof(t_lists));
	list_new->arr = filename;
	list_new->next = NULL;
	return (list_new);
}

void	push_back(t_lists **start, t_lists *list_new)
{
	t_lists *tmp;

	if (!start)
	 return ;
	if ((*start) == NULL)
		(*start) = list_new;
	else
	{
		tmp = (*start);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_new;
	}
}

void			read_map(char *filename, t_mapinfo *map)
{
	char		*line;
	int			fd;
	map->height = 0;
	map->width = 0;
	map->width2 = 0;
	map->start = NULL;

	if (!(fd = open(filename, O_RDONLY)))
		exit (0);
	while (get_next_line(fd, &line) > 0 && map->height++ > -1)
	{
		if (map->width == 0)
			map->width = count_columns(map, line);
		map->width2 = count_columns(map, line);
		if (map->width != map->width2)
			exit(0);
		push_back(&(map->start), list_new(ft_strsplit(line, ' ')));
		printf("%s\n", line);
		
		free(line);
	}
	printf("%d\n", map->height);
	printf("%d\n", map->width);
	printf("%d\n", map->width2);
	close(fd);
}

void	ft_print_map(t_mapinfo *map)
{
	t_lists *start = map->start;
	char **res;
	while (start)
	{
		res = start->arr;
		start = start->next;
	}
}

int	count_columns(t_mapinfo *map, char *line)
{
	int i = 0;
	int count;

	count = 0;
	while (line[i] != '\0')
	{
		if(ft_isdigit(line[i]))
		{
			count++;
		while ((ft_isdigit(line[i]) && line[i])
					|| line[i] == ',' || line[i] == 'x')
				i++;
		}
		else
			i++;
	}
	return (count);
}

void init_point(char **arr, int i, t_mapinfo **map)
{
	int y;

	y = 0;
	(*map)->points[i] = (t_cord*)malloc(sizeof(t_cord) * (*map)->width);
	while (y < (*map)->width)
	{
		(*map)->points[i][y] = new_point(y * 30 , i * 30 , ft_atoi(arr[y]));
		y++;
	}
}

void	ft_draw(t_mapinfo *map)
{
	int		u;
	int		v;

	v = 0;
	while (v < map->height)
	{
		u = 0;
		while (u < map->width)
		{
				mlx_pixel_put(map->mlx, map->win, map->points[v][u].x, map->points[v][u].y, map->points[v][u].col);
			u++;
		}
		v++;
	}
}

int	ft_argcheck(int argc, char **argv)
{
	if (argc == 2)
		return (2);
	if (argc != 4)
	{
		printf("Usage : ./fdf <filename> [ case_size z_size ]\n");
		return (-1);
	}
	else
	{
		if ((ft_atoi(argv[2]) == 0) || (ft_atoi(argv[3]) == 0))
		{
			printf("Usage : ./fdf <filename> [ case_size z_size ]\n");
			return (-1);
		}
	}
	return (0);
}

 void	ft_centremap(t_mapinfo *map)
 {
	 int	i;
	 int	k;
	 double	offset_x;
	 double offset_y;

	 i = 0;
	 offset_x = map->points[map->height / 2][map->width / 2].x;
	 offset_y = map->points[map->height / 2][map->width / 2].y;
	 while (i < map->height)
	 {
		 k = 0;
		 while (k < map->width)
		 {
			 map->points[i][k].x -= offset_x;
			 map->points[i][k].x += WIN_W / 2;
			 map->points[i][k].y -= offset_y;
			 map->points[i][k].y += WIN_H / 2;
			 k++;
		 }
		 i++;
	 }
 }

int main(int argc, char **argv) 
{
	int err;
	t_lists *tmp;
	int i;
    
	t_mapinfo	*map;
		if (argc != 2)
	{
		return (-1);
	}
	map = ft_memalloc(sizeof(t_mapinfo));
	read_map(argv[1], map);
	err = (ft_argcheck(argc, argv));
	ft_print_map(map);
	i = 0;
	tmp = map->start;
	map->points = (t_cord**)malloc(sizeof(t_cord*) * map->height);
	while (i < map->height)
	{
		init_point(tmp->arr, i, &map);
		tmp = tmp->next;
		i++;
	}
	//map->height = count_lines(map);
	//map->widht = count_columns(map);
   map->mlx = mlx_init();
   map->win = mlx_new_window(map->mlx, WIN_W, WIN_H, "FdF");
	ft_centremap(map);
   ft_draw(map);
   mlx_hook(map->win, 2, 5, ft_keys, &map);
   mlx_loop(map->mlx);
    return (0);
}
