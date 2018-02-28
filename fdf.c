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

 static void	key_rot(int key, t_mapinfo *map)
 {
	 if (key == 12)
		 map->rot_y += ANGL;
	 if (key == 14)
		 map->rot_y -= ANGL;
	 if (key == 13)
		 map->rot_x += ANGL;
	 if (key == 1)
		 map->rot_x -= ANGL;
	 if (key == 0)
		 map->rot_z += ANGL;
	 if (key == 2)
		 map->rot_z -= ANGL;
 }

 static void	ft_key_scale(int key, t_mapinfo *map)
 {
	 map->scale_plus = 1.01;
	 if (key == 18)
	 {
		 map->scale_plus *= 1.1;
	 }
	 if (key == 19)
	 {
		 map->scale_plus /= 1.1;
	 }

 }

 static void	ft_key_move(int key, t_mapinfo *map)
 {
	 map->scale_x = 0.0;
	 map->scale_y = 0.0;
	 if (key == 123)
		 map->scale_x -= 10.0;
	 if (key == 124)
		 map->scale_x += 10.0;
	 if (key == 125)
		 map->scale_y += 10.0;
	 if (key == 126)
		 map->scale_y -= 10.0;
 }

static int     ft_keys(int key, t_mapinfo *map)
{

	printf("key = %d\n", key);
	printf("scale = %f\n", map->scale_x);
    if (key == 53)
        exit(0);
	else if (key >= 123 && key <= 126)
	{
		ft_key_move(key, map);
		move_points(map, map->scale_x, map->scale_y);
		//ft_draw(map);
	}
	else if (key == 18 || key == 19)
	{
		ft_key_scale(key, map);
		scale_points(map, map->scale_plus);
//		ft_current_centr_cord(map);
//		ft_centr_cord(map);
//		ft_draw(map);
	}
	else if (key >= 0 && key <= 14)
	{
		key_rot(key, map);
		rotate_x(map->rot_x, map);
		rotate_y(map->rot_y, map);
		rotate_z(map->rot_z, map);
//		ft_centr_cord(map);
	//	ft_draw(map);
	}
	mlx_clear_window(map->mlx, map->win);
	ft_draw(map);
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
		//printf("%s\n", line);
		free(line);
	}
	close(fd);
}

void	ft_print_map(t_mapinfo *map)
{
	t_lists *start = map->start;
	//char **res;
	while (start)
	{
		//res = start->arr;
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
		(*map)->points[i][y] = new_point(y * SCALE  , i * SCALE  , ft_atoi(arr[y]));
		y++;
	}
}

 static void	ft_draw_instruct(t_mapinfo *map)
 {
	 int	col;

	 col = 0x00FFFFFF;
	 mlx_string_put(map->mlx, map->win, 5, 5, col, "Q and E for y rotation");
	 mlx_string_put(map->mlx, map->win, 5, 20, col, "A and D for x rotation");
	 mlx_string_put(map->mlx, map->win, 5, 35, col, "W and S for z rotation");
	 mlx_string_put(map->mlx, map->win, 5, 50, col,
					"Arrows for move. R to reset. 1 && 2 for scale");
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
	ft_draw_instruct(map);
}

 t_cord			**ft_mapcopy(t_mapinfo *map)
 {
	 int		l;
	 int		c;
	 t_cord	**new;

	 l = 0;
	 new = (t_cord**)malloc(sizeof(t_cord*) * map->height);
	 while (l < map->height)
	 {
		 new[l] = (t_cord*)malloc(sizeof(t_cord) * map->width);
		 c = 0;
		 while (c < map->width)
		 {
			 new[l][c] = map->points[l][c];
			 c++;
		 }
		 l++;
	 }
	 return (new);
 }

//int	ft_argcheck(int argc, char **argv)
//{
//	if (argc == 2)
//		return (2);
//	if (argc != 4)
//	{
//		printf("Usage : ./fdf <filename> [ case_size z_size ]\n");
//		return (-1);
//	}
//	else
//	{
//		if ((ft_atoi(argv[2]) == 0) || (ft_atoi(argv[3]) == 0))
//		{
//			printf("Usage : ./fdf <filename> [ case_size z_size ]\n");
//			return (-1);
//		}
//	}
//	return (0);
//}
//
 void ft_init_map(t_mapinfo *map)
 {
 map->rot_x = 245;
 map->rot_y = 110;
 map->rot_z = -125;
//	 map->scale_x = 0.0;
//	 map->scale_y = 0.0;
//	 scale_points(map->base, map->scale_plus);
//	 rotate_x(map->rot_x, map->base);
//	 rotate_y(map->rot_y, map->base);
//	 rotate_z(map->rot_z, map->base);
	 //scale_points(&map, map->scale_x, map->scale_y);
//	 scale_points(map, map->scale_plus);
//	 ft_centr_cord(map);
//	 rotate_x(map->rot_x, map);
//	 rotate_y(map->rot_y, map);
//	 rotate_z(map->rot_z, map);
//	 ft_draw(map);


 }

 void	ft_current_centr_cord(t_mapinfo *map)
 {
	 int i;
	 int k;
	 double centr_x;
	 double centr_y;

	  i = 0;

	 centr_x = (WIN_W - (map->width + SCALE * (map->width - 1))) / 2;
	 centr_y = (WIN_H - (map->height + SCALE * (map->height - 1))) / 2;
	 while (i < map->height)
	 {
		 k = 0;
		 while (k < map->width)
		 {
			 map->points[i][k].x -= centr_x;
			 map->points[i][k].x += WIN_W / 2.0;
			 map->points[i][k].y -= centr_y;
			 map->points[i][k].y += WIN_H / 2.0;
			 k++;
		 }
		 i++;
	 }
 }


 void	ft_centr_cord(t_mapinfo *map)
 {
	 int	i;
	 int	k;
	 double	offset_x;
	 double offset_y;

	 i = 0;
	 printf("centrcord%d\t%d\t\n", map->height, map->width);
	 offset_x = map->points[map->height / 2][map->width / 2].x;
	 offset_y = map->points[map->height / 2][map->width / 2].y;
	 while (i < map->height)
	 {
		 k = 0;
		 while (k < map->width)
		 {
			 map->points[i][k].x -= offset_x;
			 map->points[i][k].x += WIN_W / 2.0;
			 map->points[i][k].y -= offset_y;
			 map->points[i][k].y += WIN_H / 2.0;
			 k++;
		 }
		 i++;
	 }
 }

 void		scale_points(t_mapinfo *map, double scale_plus)
 {
	 int	i;
	 int	j;

	 i = 0;

	 while (i < map->height)
	 {
		 j = 0;
		 while (j < map->width)
		 {
			 map->points[i][j].x *= scale_plus;
			 map->points[i][j].y *= scale_plus;
			 map->points[i][j].z *= scale_plus;
			 j++;
		 }
		 i++;
	 }
 }


 void		move_points(t_mapinfo *map, double scale_x, double scale_y)
 {
	 int	i;
	 int	j;

	 i = 0;

	 while (i < map->height)
	 {
		 j = 0;
		 while (j < map->width)
		 {
			 map->points[i][j].x += scale_x;
			 map->points[i][j].y += scale_y;
//			 map->points[i][j].z *= scale_x;
			 j++;
		 }
		 i++;
	 }
 }

void ft_create_map(t_mapinfo **map, char *file)
 {
	 t_lists *tmp;
	 int i;

	 *map = ft_memalloc(sizeof(t_mapinfo));
	 read_map(file, *map);
	 ft_print_map(*map);
	 i = 0;
	 tmp = (*map)->start;
	 printf("H = %d\n", (*map)->height);
	 (*map)->points = (t_cord**)malloc(sizeof(t_cord*) * (*map)->height);
	 while (i < (*map)->height)
	 {
		 init_point(tmp->arr, i, map);
		 tmp = tmp->next;
		 i++;
	 }
	 (*map)->base = ft_mapcopy(*map);
 }
int main(int argc, char **argv) 
{
	t_mapinfo	*map;
		if (argc != 2)
	{
		return (-1);
	}
	ft_create_map(&map, argv[1]);
	ft_init_map(map);
   map->mlx = mlx_init();
   map->win = mlx_new_window(map->mlx, WIN_W, WIN_H, "FdF");
   ft_draw(map);
   mlx_hook(map->win, 2, 5, ft_keys, map);
   mlx_loop(map->mlx);
    return (0);
}
