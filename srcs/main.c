/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:28:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/24 02:00:25 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "bsq.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		brain(NULL);
	else
	{
		i = 1;
		while (av[i])
		{
			brain(av[i++]);
			if (ac != 2)
				write(1, "\n", 1);
		}
	}
	return (0);
}
