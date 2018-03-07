/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:04:03 by dsheptun          #+#    #+#             */
/*   Updated: 2018/01/18 16:28:53 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reader(int const fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp2;
	int		read_bit;

	while ((read_bit = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_bit] = '\0';
		tmp2 = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp2);
		if (ft_strchr(*line, '\n'))
			return ;
	}
}

int		get_next_line(int const fd, char **line)
{
	static char *stat;
	char		*tmp;
	int			i;

	if (!line || BUFF_SIZE < 1 || (read(fd, "", 0)) < 0)
		return (-1);
	stat != NULL ? tmp = ft_strdup(stat) : (0);
	if (!(i = 0) && (stat == NULL || ft_strchr(stat, '\n') == NULL))
	{
		stat == NULL ? tmp = ft_strnew(0) : (0);
		ft_reader(fd, &tmp);
	}
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[0] == '\0')
	{
		free(tmp);
		return (0);
	}
	*line = ft_strsub(tmp, 0, i);
	ft_strdel(&stat);
	stat = ft_strchr(tmp, '\n') != NULL ?
		ft_strdup(&tmp[i + 1]) : ft_strdup(&tmp[i]);
	free(tmp);
	return (1);
}
