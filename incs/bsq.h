/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:37:56 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/23 23:54:27 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define EMPTY 0
# define OBSTACLE 1
# define FULL 2
# define CHARS 3

typedef struct s_map
{
	char	*map;
	int		width;
	int		heigh;
	char	c[CHARS];
}	t_map;

int	convert_map(t_map *map, int fd);
int	get_map_infos(t_map *map, int fd);

#endif //BSQ_H /* *********************************************************** */