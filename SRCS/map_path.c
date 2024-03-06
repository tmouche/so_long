/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:45:48 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 20:27:44 by tmouche          ###   ########.fr       */
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
		if (res[i] == -1)
			return (-1);
		++i;
	}
	return (1);
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

void	_map_check_path(t_map *info, char **map)
{
	int	x1;
	int	x2;

	x1 = -1;
	while (map[++x1])
	{
		x2 = -1;
		while (map[x1][++x2])
		{
			if (map[x1][x2] == 'C')
			{
				if (_map_finished(map, x1, x2) == -1)
				{
					_write_err(2);
					_freemap(map);
					exit (EXIT_FAILURE);
				}
			}
			else if (map[x1][x2] == 'P')
			{
				info->p_x1 = x1 * 3;
				info->p_x2 = x2 * 3;
			}
		}
	}
}
