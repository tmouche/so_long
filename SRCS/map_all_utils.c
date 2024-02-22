/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_all_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 05:08:26 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 12:21:50 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"
#include "../HDRS/structure.h"
#include <stdlib.h>
#include <time.h>

int	_random(int seed, int proba)
{
	static int	mult = 1;
	int			randomnum;

	srand(time(NULL) * mult + seed);
	randomnum = rand() % proba;
	mult++;
	return (randomnum % proba);
}

void	_write_err(int err)
{
	int	write_err;

	write_err = ft_printf("Error : ");
	if (write_err > 0 && err == 1)
		ft_printf("Map non closed\n");
	else if (write_err > 0 && err == 2)
		ft_printf("Non resolvable map\n");
	else if (write_err > 0 && err == 3)
		ft_printf("wrong map shape\n");
	else if (write_err > 0 && err == 404)
		ft_printf("Map not found\n");
}

void	_reset_map(char **map)
{
	int	x1;
	int	x2;

	x1 = 0;
	while (map[x1])
	{
		x2 = 0;
		while (map[x1][x2])
		{
			if (map[x1][x2] == '2')
				map[x1][x2] = '0';
			x2++;
		}
		x1++;
	}
}
