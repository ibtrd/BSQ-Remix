/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 01:09:42 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 18:40:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_vector.h"
#include "libft.h"
#include "bsq.h"

static int	add_pixel(t_map *map, t_vector *print, char c);
static int	add_color(t_vector *print, int i);

int	display_map(t_map *map)
{
	const int	size = map->heigh * (map->width + 1);
	t_vector	print;
	int			i;

	if (ft_vector_init(&print, sizeof(char), size, NULL))
		return (1);
	i = 0;
	while (i < size)
	{
		if (add_pixel(map, &print, map->map[i]))
			return (FAILURE);
		i++;
	}
	if (write(STDOUT_FILENO, print.ptr, print.total) != (long)print.total)
	{
		ft_vector_free(&print);
		return (FAILURE);
	}
	ft_vector_free(&print);
	return (SUCCESS);
}

static int	add_pixel(t_map *map, t_vector *print, char c)
{
	if (c == map->c[FULL])
	{
		if (add_color(print, FULL))
			return (FAILURE);
	}
	else if (c == map->c[OBSTACLE])
	{
		if (add_color(print, OBSTACLE))
			return (FAILURE);
	}
	else if (c == '\n')
		ft_vector_add(print, "\n");
	else if (ft_vector_join(print, "  ", 2))
		return (FAILURE);
	return (SUCCESS);
}

static int	add_color(t_vector *print, int i)
{
	const char	*colors[] = {NULL, RED, GREEN};

	return (ft_vector_join(print, (char *)colors[i], ft_strlen(colors[i]))
		|| ft_vector_join(print, "  ", 2)
		|| ft_vector_join(print, RESET, ft_strlen(RESET)));
}
