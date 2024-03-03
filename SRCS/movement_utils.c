/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:16:29 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/03 17:36:12 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"

void	_reset_chara(t_map *info, t_block ***s_map, int x1, int x2)
{
	int	offset_x1;
	int	offset_x2;

	offset_x1 = 0;
	while (offset_x1 < 3)
	{
		offset_x2 = 0;
		while (offset_x2 < 3)
		{
			s_map[x1 + offset_x1][x2 + offset_x2] = info->empty;
			++offset_x2;
		}
		++offset_x1;
	}
}

void	_replace_chara(t_block ***s_map, t_block *block, int x1, int x2)
{
	int	offset_x1;
	int	offset_x2;

	offset_x1 = 0;
	while (offset_x1 < 3)
	{
		offset_x2 = 0;
		while (offset_x2 < 3)
		{
			s_map[x1 + offset_x1][x2 + offset_x2] = block;
			++offset_x2;
		}
		++offset_x1;
	}
}
