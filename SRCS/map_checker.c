/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:18:55 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/23 21:50:00 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "../HDRS/map.h"
#include <stddef.h>
#include <unistd.h>

static int	_ispossible(char **map, int x1, int x2, char c);

static int	_pathfinder(char **map, int x1, int x2, char c)
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
		_ispossible(map, x1, x2, c);
	}
	if (map[x1][x2] == c && stop == 0)
		stop = 1;
	return (0);
}

static int	_ispossible(char **map, int x1, int x2, char c)
{
	if (_pathfinder(map, x1 - 1, x2, c) == 0)
		return (0);
	if (_pathfinder(map, x1, x2 - 1, c) == 0)
		return (0);
	if (_pathfinder(map, x1, x2 + 1, c) == 0)
		return (0);
	if (_pathfinder(map, x1 + 1, x2, c) == 0)
		return (0);
	return (-1);
}

static int	_map_finished(char **map, int x1, int x2)
{
	int	check_e;
	int	check_p;

	check_e = _ispossible(map, x1, x2, 'E');
	_reset_map(map);
	_pathfinder(NULL, 0, 0, 'a');
	check_p = _ispossible(map, x1, x2, 'P');
	_reset_map(map);
	_pathfinder(NULL, 0, 0, 'a');
	if (check_e == 0 && check_p == 0)
		return (0);
	return (-1);
}

static int	_map_resolvable(t_map *info, int x1, int x2, char **map)
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
		return (_map_finished(map, x1, x2));
	}
	return (c_epc[2]);
}

int	_map_checker(t_map *info, char **map)
{
	int	x1;
	int	x2;

	x1 = -1;
	if (!map)
		return (_write_err(404), -1);
	while (map[++x1])
	{
		x2 = -1;
		while (map[x1][++x2])
		{
			if (x1 == 0 || x2 == 0 || map[x1][x2 + 1] == 0 || map[x1 + 1] == 0)
				if (map[x1][x2] != '1')
					return (_write_err(1), -1);
			if (_map_resolvable(info, x1, x2, map) == -1)
				return (_write_err(2), -1);
		}
		if (x2 != (int)ft_strlen(map[0], 0))
			return (_write_err(3), -1);
	}
	_init_t_map(info, x1, x2, _map_resolvable(info, 0, 0, map));
	if (_map_resolvable(info, 0, 0, NULL) == -1)
		return (_write_err(2), -1);
	return (0);
}
