/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 01:09:42 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 04:04:10 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_vector.h"
#include "bsq.h"

int	display_map(t_map *map)
{
	write(STDOUT_FILENO, map->map, map->heigh * (map->width + 1));
	return (SUCCESS);
}
