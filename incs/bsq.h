/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:37:56 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 16:03:55 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define MAP_ERROR "map error\n"
# define RED "\e[39;41m"
# define GREEN "\e[30;42m"
# define RESET "\e[0m"

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

void	brain(char *filepath);
int		convert_map(t_map *map, int fd);
int		get_map_infos(t_map *map, int fd);
int		display_map(t_map *map);
int		solver(t_map *map);

#endif //BSQ_H /* *********************************************************** */