/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:18:55 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/16 11:18:00 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../ft_error.h"
#include "../ft_movement.h"
#include "../ft_map.h"

static int	ft_ispossible(char **map, int x1, int x2, char c);

static int	ft_pathfinder(char **map, int x1, int x2, char c)
{
	static int	stop = 0;

	if (!map)
	{
		stop = 0;
		return (0);
	}
	if (map[x1][x2] == '1' && stop == 0)
		return (-1);
	if (map[x1][x2] == '2' && stop == 0)
		return (-1);
	if (map[x1][x2] == '0' && stop == 0)
	{
		map[x1][x2] = '2';
		ft_ispossible(map, x1, x2, c);
	}
	if (map[x1][x2] == c && stop == 0)
		stop = 1;
	return (0);
}

static int	ft_ispossible(char **map, int x1, int x2, char c)
{
	if (ft_pathfinder(map, x1 - 1, x2, c) == 0)
		return (0);
	if (ft_pathfinder(map, x1, x2 - 1, c) == 0)
		return (0);
	if (ft_pathfinder(map, x1, x2 + 1, c) == 0)
		return (0);
	if (ft_pathfinder(map, x1 + 1, x2, c) == 0)
		return (0);
	return (-1);
}

static int	ft_map_finished(char **map, int x1, int x2)
{
	int	check_e;
	int	check_p;

	check_e = ft_ispossible(map, x1, x2, 'E');
	ft_reset_map(map);
	ft_pathfinder(NULL, 0, 0, 'a');
	check_p = ft_ispossible(map, x1, x2, 'P');
	ft_reset_map(map);
	ft_pathfinder(NULL, 0, 0, 'a');
	if (check_e == 0 && check_p == 0)
		return (0);
	return (-1);
}

static int	ft_map_resolvable(t_map *info, int x1, int x2, char **map)
{
	static int	c_epc[3] = {0, 0, 0};

	if (!map)
	{
		if (c_epc[0] == 0 || c_epc[1] == 0 || c_epc[2] == 0)
			return (-1);
		return (0);
	}
	if (map[x1][x2] == 'E')
		if (++c_epc[0] > 1)
			return (-1);
	if (map[x1][x2] == 'P')
	{
		info->p_x1 = x1 * 3;
		info->p_x2 = x2 * 3;
		if (++c_epc[1] > 1)
			return (-1);
	}
	if (map[x1][x2] == 'C')
	{
		c_epc[2]++;
		return (ft_map_finished(map, x1, x2));
	}
	return (c_epc[2]);
}

int	ft_map_checker(t_map *info, char **map)
{
	int	x1;
	int	x2;

	x1 = -1;
	if (!map)
		return (ft_write_err(404), -1);
	while (map[++x1])
	{
		x2 = -1;
		while (map[x1][++x2])
		{
			if (x1 == 0 || x2 == 0 || map[x1][x2 + 1] == 0 || map[x1 + 1] == 0)
				if (map[x1][x2] != '1')
					return (ft_write_err(1), -1);
			if (ft_map_resolvable(info, x1, x2, map) == -1)
				return (ft_write_err(2), -1);
		}
		if (x2 != (int)ft_strlen(map[0]))
			return (ft_write_err(3), -1);
	}
	ft_map_struct(info, x1, x2, ft_map_resolvable(info, 0, 0, map));
	if (ft_map_resolvable(info, 0, 0, NULL) == -1)
		return (ft_write_err(2), -1);
	return (0);
}
