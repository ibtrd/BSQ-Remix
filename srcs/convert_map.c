/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:05:26 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 01:07:31 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "bsq.h"
#include "ft_vector.h"
#include "libft.h"
#include "ft_printf.h"

int	set_infos(t_map *map, char *line)
{
	int		i;
	char	*l2;

	i = ft_strlen(line);
	if (i < 4 || line[--i] != '\n')
		return (FAILURE);
	map->c[FULL] = line[--i];
	map->c[OBSTACLE] = line[--i];
	map->c[EMPTY] = line[--i];
	line[i] = '\0';
	errno = 0;
	map->heigh = ft_strtoi(line, &l2);
	if (*l2 || errno || map->heigh < 0)
		return (FAILURE);
	return (SUCCESS);
}

int	get_map_infos(t_map *map, int fd)
{
	char	*line;

	if (get_next_line(fd, &line) == FAILURE || !line)
		return (FAILURE);
	if (set_infos(map, line))
	{
		free(line);
		return (FAILURE);
	}
	free(line);
	return (SUCCESS);
}

int	convert_line(t_map *map, char *line, t_vector *buffer)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == map->c[EMPTY])
			line[i] = EMPTY;
		else if (line[i] == map->c[OBSTACLE])
			line[i] = OBSTACLE;
		else
			return (FAILURE);
		i++;
	}
	if (line[i] != '\n')
		return (FAILURE);
	if (map->width == 0)
		map->width = i;
	else if (map->width != i)
		return (FAILURE);
	if (ft_vector_join(buffer, line, i))
		return (FAILURE);
	return (SUCCESS);
}

int	convert_map(t_map *map, int fd)
{
	t_vector	buffer;
	char		*line;
	int			n;

	if (ft_vector_init(&buffer, sizeof(char), 0, NULL))
		return (FAILURE);
	n = 0;
	while (get_next_line(fd, &line) != FAILURE && line)
	{
		if (convert_line(map, line, &buffer))
		{
			ft_vector_free(&buffer);
			return (FAILURE);
		}

		// ft_dprintf(2, "%s", line);
		free(line);
	}
	map->map = buffer.ptr;
	return (SUCCESS);
}
