/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 06:05:40 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 06:09:53 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "bsq.h"
#include "libft.h"

static int	set_infos(t_map *map, char *line);
static int	check_duplicates(char param[3]);

int	get_map_infos(t_map *map, int fd)
{
	char	*line;

	if (get_next_line(fd, &line) == FAILURE || !line)
		return (FAILURE);
	if (set_infos(map, line) || check_duplicates(map->c))
	{
		free(line);
		return (FAILURE);
	}
	free(line);
	return (SUCCESS);
}

static int	set_infos(t_map *map, char *line)
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

static int	check_duplicates(char param[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 3)
		{
			if (param[i] == param[j])
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
