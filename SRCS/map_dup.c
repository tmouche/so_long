/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:34:19 by tmouche           #+#    #+#             */
/*   Updated: 2024/01/10 11:24:26 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_map.h"
#include "../ft_structure.h"
#include "../libft/libft.h"
#include <stdlib.h>

static void	ft_square_three(char **map, int x1, int x2, char c)
{
	int	n_x1;
	int	n_x2;
	
	n_x1 = 0;
	while (n_x1 < 3)
	{
		n_x2 = 0;
		while (n_x2 < 3)
		{
			map[x1 + n_x1][x2 + n_x2] = c;
			n_x2++;
		}
		n_x1++;
	}
}

static void	ft_map_charger(t_map *info, char **map)
{
	int	x1;
	int	x2;
	
	x1 = 0;
	while (info->map[x1])
	{
		x2 = 0;
		while (info->map[x1][x2])
		{
			ft_square_three(map, x1 * 3, x2 * 3, info->map[x1][x2]);
			x2++;
		}
		x1++;
	}
}

char	**ft_map_dup(t_map *info)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(info->map_height * 3 + 1, sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < info->map_height * 3)
	{
		new_map[i] = ft_calloc(info->map_width * 3 + 1, 1);
		if (!new_map[i])
			return (ft_freemap(new_map), NULL);
		i++;
	}
	ft_map_charger(info, new_map);
	ft_freemap(info->map);
	return (new_map);
}