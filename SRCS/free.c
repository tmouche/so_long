/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:54:22 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 12:29:32 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include <stdlib.h>

void	_freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void	_free_s_map(t_block ***s_map, int stop)
{
	int	temp;
	int	x1;
	int	x2;

	x1 = 0;
	while (s_map[x1])
	{
		x2 = 0;
		if (stop > 0)
		{
			while (s_map[x1][x2])
			{
				if (s_map[x1][x2]->nature == 'D' && s_map[x1][x2]->bad)
					free (s_map[x1][x2]->bad);
				free (s_map[x1][x2]);
				x2 += 3;
			}
		}
		temp = -1;
		while (++temp < 3)
			free (s_map[x1 + temp]);
		x1 += 3;
	}
	free (s_map);
}

void	_free_all(t_struct *glob, int stop)
{
	_freemap(glob->info->c_map);
	if (stop <= 1)
		_free_s_map(glob->info->s_map, stop);
	exit (EXIT_FAILURE);
}