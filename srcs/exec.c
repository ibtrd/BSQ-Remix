/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:50:09 by mjuffard          #+#    #+#             */
/*   Updated: 2024/07/24 18:34:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "bsq.h"

static int	fill_map(int *int_map, t_map *map, int index_max);
static int	*alloc_int_map(t_map map);
static int	fill_int_map(int *int_map, int width, int heigh);
static void	get_min(int *int_map, int width, int i, int *max, int *index_max);

int	solver(t_map *map)
{
	int	*int_map;
	int	index_max;
	int	ret;

	int_map = alloc_int_map(*map);
	if (NULL == int_map)
		return (EXIT_FAILURE);
	index_max = fill_int_map(int_map, map->width, map->heigh);
	ret = fill_map(int_map, map, index_max);
	free(int_map);
	return (ret);
}

static int	*alloc_int_map(t_map map)
{
	int	*int_map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	int_map = malloc(sizeof(int) * (map.heigh * map.width));
	if (NULL == int_map)
		return (NULL);
	while (j < map.width * map.heigh)
	{
		if ('\n' == map.map[i])
			i++;
		if (map.map[i] == map.c[OBSTACLE])
			int_map[j] = 0;
		else if (j < map.width || j % map.width == 0)
			int_map[j] = 1;
		else
			int_map[j] = -1;
		i++;
		j++;
	}
	return (int_map);
}

static int	fill_int_map(int *int_map, int width, int heigh)
{
	int	i;
	int	max;
	int	index_max;

	i = 0;
	index_max = 0;
	max = 0;
	while (i < width * heigh)
	{
		if (int_map[i] == -1)
			get_min(int_map, width, i, &max, &index_max);
		if (1 == int_map[i] && 0 == max)
		{
			max = 1;
			index_max = i;
		}
		i++;
	}
	return (index_max);
}

static void	get_min(int *int_map, int width, int i, int *max, int *index_max)
{
	int	min;

	min = int_map[i - 1];
	if (min > int_map[i - width])
		min = int_map[i - width];
	if (min > int_map[i - width - 1])
		min = int_map[i - width - 1];
	int_map[i] = min + 1;
	if (min + 1 > *max)
	{
		*max = min + 1;
		*index_max = i;
	}
}

static int	fill_map(int *int_map, t_map *map, int index_max)
{
	int	x;
	int	y;
	int	n;
	int	m;

	n = 0;
	y = index_max / map->width;
	if (index_max == 0 && int_map[index_max] == 0)
		return (EXIT_FAILURE);
	while (n++ < int_map[index_max])
	{
		m = 0;
		x = index_max % map->width;
		while (m++ < int_map[index_max])
		{
			map->map[y * (map->width + 1) + x] = map->c[FULL];
			x--;
		}
		y--;
	}
	return (EXIT_SUCCESS);
}
