/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:45:48 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/07 14:17:43 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "../HDRS/map.h"
#include <stddef.h>
#include <unistd.h>

static inline void	_set_off(int (*off)[2], int x1, int x2)
{
	off[0][0] = x1;
	off[0][1] = x2 + 1;
	off[1][0] = x1;
	off[1][1] = x2 - 1;
	off[2][0] = x1 + 1;
	off[2][1] = x2;
	off[3][0] = x1 - 1;
	off[3][1] = x2;
}

static inline int	_fill_block(char **map, int x1, int x2, char goal)
{
	if (map[x1][x2] == '0' || map[x1][x2] == 'C')
	{
		map[x1][x2] = '2';
		return (2);
	}
	else if (map[x1][x2] == goal)
		return (1);
	return (0);
}

static int	_path_finder(char **map, int x1, int x2, char goal)
{
	int	off[4][2];
	int	res;
	int	i;

	i = 0;
	_set_off(off, x1, x2);
	while (i < 4)
	{
		res = _fill_block(map, off[i][0], off[i][1], goal);
		if (res == 1)
			return (1);
		else if (res == 2)
			if (_path_finder(map, off[i][0], off[i][1], goal) == 1)
				return (1);
		++i;
	}
	return (0);
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
	if (res_e != 1)
		return (-1);
	map_copy = _copy_map(map);
	if (!map_copy)
	{
		_freemap(map);
		exit (EXIT_FAILURE);
	}
	res_p = _path_finder(map_copy, x1, x2, 'P');
	_freemap(map_copy);
	if (res_p != 1)
		return (-1);
	return (0);
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
