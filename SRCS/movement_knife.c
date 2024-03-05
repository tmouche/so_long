/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_knife.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:22:38 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/05 16:34:13 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"

void	_knife(t_map *info, t_block ***s_map, int keycode)
{
	if (keycode == 65364)
	{
		if (s_map[info->p_x1 + 3][info->p_x2 + 1]->type == 'D')
			if (s_map[info->p_x1 + 3][info->p_x2 + 1]->bad->state >= 0)
				s_map[info->p_x1 + 3][info->p_x2 + 1]->bad->state = -1;
	}
	else
	{
		if (s_map[info->p_x1 - 1][info->p_x2 + 1]->type == 'D')
			if (s_map[info->p_x1 - 1][info->p_x2 + 1]->bad->state >= 0)
				s_map[info->p_x1 - 1][info->p_x2 + 1]->bad->state = -1;
	}
}