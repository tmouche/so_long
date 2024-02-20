/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_chara.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:59:20 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 13:12:21 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_structure.h"
#include "../ft_movement.h"

void	ft_move_opps(t_opps *bad, char **map)
{
	ft_reset_chara(map, bad->x1, bad->x2);
	if (bad->dir == 0)
	{
		map[bad->x1 + bad->sens][bad->x2] = 'D';
		bad->x1 += bad->sens;
	}
	else
	{
		map[bad->x1][bad->x2 + bad->sens] = 'D';
		bad->x2 += bad->sens;
	}
	ft_replace_chara(map, bad->x1, bad->x2, 'D');
}

void	ft_move_player(t_map *info, int d_x1, int d_x2)
{
	ft_reset_chara(info->map, info->p_x1, info->p_x2);
	info->map[info->p_x1 + d_x1][info->p_x2 + d_x2] = 'P';
	info->p_x2 += d_x2;
	info->p_x1 += d_x1;
	if (d_x1 != 0 || d_x2 != 0)
		info->step++;
	ft_replace_chara(info->map, info->p_x1, info->p_x2, 'P');
}
