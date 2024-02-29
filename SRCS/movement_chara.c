/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_chara.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:51:23 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/29 18:37:38 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/movement.h"
#include <unistd.h>
#include <stdio.h>

void	_move_opps(t_map *info, t_block ***s_map, t_opps *bad)
{
	_reset_chara(info, s_map, bad->x1, bad->x2);
	if (bad->dir == 0)
		bad->x1 += bad->sens;
	else
		bad->x2 += bad->sens;
	_replace_chara(s_map, bad, bad->x1, bad->x2, 'D');
}

void	_move_player(t_map *info, int d_x1, int d_x2)
{
	_reset_chara(info, info->s_map, info->p_x1, info->p_x2);
	info->s_map[info->p_x1 + d_x1][info->p_x2 + d_x2]->nature = 'P';
	info->p_x2 += d_x2;
	info->p_x1 += d_x1;
	if (d_x1 != 0 || d_x2 != 0)
		info->step++;
	_replace_chara(info->s_map, NULL, info->p_x1, info->p_x2, 'P');
}
