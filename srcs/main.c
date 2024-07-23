/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:28:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 01:04:56 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "bsq.h"

int	main(int ac, char **av)
{
	t_map	map;

	map = (t_map){0};
	(void)ac;
	(void)av;
	if (get_map_infos(&map, STDIN_FILENO))
		return (1);
	if (convert_map(&map, STDIN_FILENO))
		return (1);
	ft_dprintf(2, "charset=%s | height=%d | width=%d\n", map.c, map.heigh, map.width);
	write(2, map.map, map.heigh * map.width);
	return (0);
}
