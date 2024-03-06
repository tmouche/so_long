/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:18:55 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 16:42:15 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "../HDRS/map.h"
#include <stddef.h>
#include <unistd.h>

static int	_path_finder(char **map, int x1, int x2, char goal);

static int	_is_possible(char **map, int x1, int x2, int c)
{
	int	res[4];
	int	i;

	res[0] = _path_finder(map, x1, x2 + 1, c);
	res[1] = _path_finder(map, x1, x2 - 1, c);
	res[2] = _path_finder(map, x1 + 1, x2, c);
	res[3] = _path_finder(map, x1 - 1, x2, c);
	i = 0;
	while (i < 4)
	{
		if (res[i] == 1)
			return (1);
		++i;
	}
	return (-1);
}

static int	_path_finder(char **map, int x1, int x2, char goal)
{
	char	actual;

	actual = map[x1][x2];
	if (actual == '0' || actual == 'C')
	{
		map[x1][x2] = '2';
		return (_is_possible(map, x1, x2, goal));
	}
	if (actual == '1' || actual == '2' || (actual == 'E' && goal != 'E'))
		return (-1);
	else
		return (1);
}

static int	_map_finished(char **map, int x1, int x2)
{
	char	**map_copy;
	int		res_e;
	int		res_p;

	map_copy = _copy_map(map);
	if (!map_copy)
	{
		_freemap(map);
		exit (EXIT_FAILURE);
	}
	res_e = _path_finder(map_copy, x1, x2, 'E');
	_freemap(map_copy);
	map_copy = _copy_map(map);
	if (!map_copy)
	{
		_freemap(map);
		exit (EXIT_FAILURE);
	}
	res_p = _path_finder(map_copy, x1, x2, 'P');
	_freemap(map_copy);
	if (res_e == 1 && res_p == 1)
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
			_check_char(map, map[x1][x2]);
		}
		if (x2 != (int)ft_strlen(map[0], 0))
			return (_write_err(3), -1);
	}
	_init_t_map(info, x1, x2, _map_resolvable(info, 0, 0, map));
	if (_map_resolvable(info, 0, 0, NULL) == -1)
		return (_write_err(2), -1);
	return (0);
}
