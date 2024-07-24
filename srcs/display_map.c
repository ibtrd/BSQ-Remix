/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 01:09:42 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 05:53:26 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_vector.h"
#include "bsq.h"

int	display_map(t_map *map)
{
	const int	size = map->heigh * (map->width + 1);

	return (write(STDOUT_FILENO, map->map, size) != size);
}
