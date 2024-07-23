/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:28:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/23 23:19:51 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "bsq.h"

int	main(int ac, char **av)
{
	t_map	map;

	(void)ac;
	(void)av;
	if (convert_map(&map, STDIN_FILENO))
		return (1);
	return (0);
}
