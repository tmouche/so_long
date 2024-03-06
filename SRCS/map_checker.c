/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:35:29 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 20:22:25 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "../HDRS/map.h"
#include <stddef.h>
#include <unistd.h>

static void	_check_e_p(char **map, int *counter)
{
	if (counter[0] != 1 || counter[1] != 1)
	{
		_write_err(2);
		_freemap(map);
		exit(EXIT_FAILURE);
	}
}

static int	*_map_resolvable(t_map *info, char c)
{
	static int	c_epc[2] = {0, 0};

	if (c == 'E')
		++c_epc[0];
	if (c == 'P')
		++c_epc[1];
	if (c == 'C')
		++info->collect;
	return (c_epc);
}

int	_map_checker(t_map *info, char **map)
{
	int	*counter;
	int	x1;
	int	x2;

	if (!map)
		return (_write_err(404), -1);
	x1 = -1;
	info->collect = 0;
	while (map[++x1])
	{
		x2 = -1;
		while (map[x1][++x2])
		{
			if (x1 == 0 || x2 == 0 || map[x1][x2 + 1] == 0 || map[x1 + 1] == 0)
				if (map[x1][x2] != '1')
					return (_write_err(1), -1);
			_check_char(map, map[x1][x2]);
			counter = _map_resolvable(info, map[x1][x2]);
		}
	}
	_check_e_p(map, counter);
	_init_t_map(info, x1, x2);
	_map_check_path(info, map);
	return (0);
}
