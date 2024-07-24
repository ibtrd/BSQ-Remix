/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 01:09:42 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 02:38:02 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_vector.h"
#include "bsq.h"

int	display_map(t_map *map)
{
	t_vector	buffer;
	int			i;
	int			j;

	if (ft_vector_init(&buffer, sizeof(char), map->heigh * (map->width + 1), NULL))
		return (FAILURE);
	i = 0;
	while (i < map->heigh)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_vector_add(&buffer, map->c + map->map[(i * map->width) + j]))
				return (FAILURE);
			j++;
		}
		if (ft_vector_add(&buffer, "\n"))
			return (FAILURE);
		i++;
	}
	write(1, buffer.ptr, buffer.total);
	ft_vector_free(&buffer);
	return (SUCCESS);
}
