/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fixer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:34:19 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 17:04:47 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include <time.h>
#include <stdlib.h>

int	_random(int seed, int proba)
{
	static int	mult = 1;
	int			randomnum;

	srand(time(NULL) * mult + seed);
	randomnum = rand() % proba;
	mult++;
	return (randomnum % proba);
}

static int	_fixer_opps(t_opps **bad, int x1, int x2)
{
	t_opps	*temp;

	temp = _lstnew(x1, x2);
	if (!temp)
		return (_lstclear(bad), -1);
	if (_random(1, 2) == 0)
		temp->dir = 1;
	if (_random(1, 2) == 0)
		temp->sens = -1;
	if (x1 % 3 == 0)
		temp->state == 0;
	else if (x1 % 2 == 0)
		temp->state == 1;
	else
		temp->state == 2;
	_lstadd_back(bad, temp);
	return (0);
}

void	_fixer_map(char ** map, t_map *info, t_opps **bad)
{
	int	x1;
	int	x2;

	x1 = -1;
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
				if (_random(x1 + x2, info->map_width) == 0)
				{
					info->map[x1][x2] = 'D';
					_fixer_opps(bad, x1, x2);
				}
			}
		}
	}
	info->bad = bad;
}
