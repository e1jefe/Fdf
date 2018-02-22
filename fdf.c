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

t_lists *list_new(char **filename)
{

	t_lists *new_list;

	new_list = ft_memalloc(sizeof(t_lists));
	new_list->points = filename;
	new_list->next = NULL;
	return (new_list);
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
	map->height2 = 0;
	map->width = 0;
	map->width2 = 0;
	map->start = NULL;

	if (!(fd = open(filename, O_RDONLY)))
		exit (0);
	while (get_next_line(fd, &line) > 0 && map->height2++ > -1)
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
	printf("%d\n", map->height2);
	printf("%d\n", map->width2);
	close(fd);
}

void	ft_print_map(t_mapinfo *map)
{
	t_lists *start = map->start;
	char **res;
	while (start)
	{
		res = start->points;
		start = start->next;
	}
}

// int	count_lines(t_mapinfo *map)
// {
// 	t_lists *tmp = map->start;
// 	int i = 0;

// 	while (tmp)
// 	{
// 		if (tmp[i] == ' ')
// 		{

// 		}
// 		tmp = tmp->next;
// 	}
// 	printf("lines: %d\n", i);
// 	return (i);
// }

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

int main(int argc, char **argv) {
    
	t_mapinfo	*map;
		if (argc != 2)
	{
		return (-1);
	}
	map = ft_memalloc(sizeof(t_mapinfo));
	// printf("1\n");
//	ft_bzero(map, sizeof(t_mapinfo));
	read_map(argv[1], map);
	//printf("%s\n", "yoyo");
	// printf("2\n");
	ft_print_map(map);
	// printf("3\n");
	//map->height = count_lines(map);
	// printf("4\n");
	//map->widht = count_columns(map);
	//printf("wliapa:%d\n", map->height2);

//	map->uk = ft_memalloc(sizeof(t_cord) * !!!!!!!!!!!!!res!!!!!!!!!!!!!!!!!!!!!!)
	//printf("%s", map.map[0]);
	
 //   map->mlx = mlx_init();
 //   map->win = mlx_new_window(map->mlx, WIN_W, WIN_H, "FdF");
	// ft_init_map(&map);
  //  mlx_hook(map->win, 2, 5, ft_keys, &map);
  //  mlx_loop(map->mlx);
    return (0);
}
