/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 01:09:42 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 01:18:19 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "bsq.h"

int	display_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->heigh)
	{
		j = 0;
		while (j < map->width)
		{
			write(1, map->c + map->map[(i * map->width) + j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
