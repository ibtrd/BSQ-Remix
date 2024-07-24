/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 01:27:25 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 04:49:00 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "libft.h"
#include "bsq.h"

int	solve(int fd)
{
	t_map	map;
	int 	status;

	map = (t_map){0};
	if (get_map_infos(&map, fd))
		return (1);
	if (convert_map(&map, fd))
		return (1);
	// ft_dprintf(2, "charset=%s | height=%d | width=%d\n", map.c, map.heigh, map.width);
	status = solver(&map);
	if (!status)
		display_map(&map);
	free(map.map);
	return (status);
}

void	brain(char *filepath)
{
	int	fd;

	if (!filepath)
		fd = STDIN_FILENO;
	else
		fd = open(filepath, O_RDONLY);
	if (fd == -1 || solve(fd))
		write(STDERR_FILENO, "map error\n", 10);
	if (fd > 0)
		close(fd);
}


