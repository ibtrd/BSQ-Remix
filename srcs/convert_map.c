/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:05:26 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 21:53:56 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bsq.h"
#include "libft.h"

static int	convert_line(t_map *map, char *line, t_vector *buffer);

int	convert_map(t_map *map, int fd)
{
	t_vector	buffer;
	char		*line;
	int			n;

	if (ft_vector_init(&buffer, sizeof(char), map->heigh * 2, NULL))
		return (FAILURE);
	n = 0;
	while (get_next_line(fd, &line) != FAILURE && line)
	{
		if (convert_line(map, line, &buffer))
		{
			ft_vector_free(&buffer);
			return (FAILURE);
		}
		free(line);
		n++;
	}
	map->map = buffer.ptr;
	return (n != map->heigh);
}

static int	convert_line(t_map *map, char *line, t_vector *buffer)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != map->c[EMPTY] && line[i] != map->c[OBSTACLE])
			return (FAILURE);
		i++;
	}
	if (line[i] != '\n')
		return (FAILURE);
	if (map->width == 0)
		map->width = i;
	else if (map->width != i)
		return (FAILURE);
	if (ft_vector_join(buffer, line, i + 1))
		return (FAILURE);
	return (SUCCESS);
}
