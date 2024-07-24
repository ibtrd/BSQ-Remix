/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:50:09 by mjuffard          #+#    #+#             */
/*   Updated: 2024/07/24 02:03:48 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "bsq.h"

int	*alloc_int_map(t_map *map)
{
	int	*int_map;
	int	i;

	i = 0;
	int_map = malloc(sizeof(int) * (map->heigh * map->width));
	if (NULL == int_map)
		return (NULL);
	while (i < map->width * map->heigh)
	{
		if (map->map[i] == OBSTACLE)
			int_map[i] = 0;
		else if (i < map->width || i % map->width == 0)
			int_map[i] = 1;
		else
			int_map[i] = -1;
		i++;
	}
	return (int_map);
}

int	fill_int_map(int *int_map, t_map *map)
{
	int	i;
	int	n;
	int	max;
	int	index_max;

	i = 0;
	index_max = 0;
	max = 0;
	while (i < map->width * map->heigh)
	{
		if (int_map[i] == -1)
		{
			n = int_map[i - 1];
			if (n > int_map[i - map->width])
				n = int_map[i - map->width];
			if (n > int_map[i - map->width - 1])
				n = int_map[i - map->width - 1];
			int_map[i] = n + 1;
			if (n + 1 > max)
			{
				max = n + 1;
				index_max = i;
			}
		}
		i++;
	}
	return (index_max);
}

int	fill_map(int *int_map, t_map *map, int index_max)
{
	int	i;
	int	j;

	i = 0;
	if (index_max == 0 && int_map[index_max] == 0)
	{
		free(int_map);
		return (EXIT_FAILURE);
	}
	while (i < int_map[index_max])
	{
		j = 0;
		while (j < int_map[index_max])
		{
			map->map[(index_max - j) - (map->width * i)] = FULL;
			j++;
		}
		i++;;
	}
	free(int_map);
	return (EXIT_SUCCESS);
}

void	print_int_map(int *int_map, int x, int y)
{
	int i = 0;
	while (i < x * y)
	{
		printf("%d", int_map[i]);
		i++;
	}
}

int	test(t_map *map)
{
	int	*int_map;
	int	index_max;

	int_map = alloc_int_map(map);
	if (NULL == int_map)
		return (EXIT_FAILURE);
	index_max = fill_int_map(int_map, map);
	return (fill_map(int_map, map,index_max));
}
