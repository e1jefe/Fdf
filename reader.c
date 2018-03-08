/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:12:31 by dsheptun          #+#    #+#             */
/*   Updated: 2018/03/08 13:03:09 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			counter_lines(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("Error opening file.\n");
		exit(-1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
		line = NULL;
	}
	if (get_next_line(fd, &line) < 0)
	{
		ft_putstr("Error opening file.\n");
		exit(0);
	}
	close(fd);
	return (height);
}

t_mapinfo			reader_map(char *filename)
{
	char		*line;
	t_mapinfo	file;
	int			fd;
	int			i;

	i = 0;
	file.height = 0;
	file.map = NULL;
	if (!(fd = open(filename, O_RDONLY)))
		return (file);
	file.height = counter_lines(filename);
	file.map = (char**)malloc(sizeof(char*) * file.height);
	while (i < file.height)
	{
		get_next_line(fd, &line);
		file.map[i++] = line;
	}
	close(fd);
	return (file);
}

void				free_file(t_mapinfo map)
{
	int l;

	l = 0;
	while (l < map.height)
	{
		free(map.map[l]);
		l++;
	}
	free(map.map);
}
