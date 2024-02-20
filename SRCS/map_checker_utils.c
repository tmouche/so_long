/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 05:08:26 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 11:29:05 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <../ft_map.h>

int	ft_random(int seed, int proba)
{
	static int	mult = 1;
	int			randomnum;

	
	srand(time(NULL) * mult + seed);
	randomnum = rand() % proba;
    mult++;
    return (randomnum % proba);
}

void	ft_write_err(int err)
{
	int	write_err;

	write_err = write(1, "error\n", 6);
	if (write_err > 0 && err == 1)
		write(1, "map non closed\n", 15);
	else if (write_err > 0 && err == 2)
		write(1, "Non resolvable map\n", 20);
	else if (write_err > 0 && err == 3)
		write(1, "wrong map shape\n", 16);
	else if (write_err > 0 && err == 404)
		write(1, "map not found\n", 15);
}

void	ft_set_map(t_map *info, t_opps **bad)
{
	int	x1;
	int	x2;

	x1 = -1;
	bad = NULL;
	while (info->map[++x1])
	{
		x2 = -1;
		while (info->map[x1][++x2])
		{
			if (info->map[x1][x2] == '1' && x1 != 0
					&& x1 != info->map_height - 1
					&& x2 != 0 && x2 != info->map_width - 1)
				info->map[x1][x2] = '2';
			if (info->map[x1][x2] == '0')
			{
				if (ft_random(x1 + x2, info->map_width) == 0)
				{
					info->map[x1][x2] = 'D';
					ft_pos_opps(bad, x1, x2);
				}
			}
		}
	}
	info->bad = &bad;
}

void	ft_reset_map(char **map)
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
