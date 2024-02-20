/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:01:52 by tmouche           #+#    #+#             */
/*   Updated: 2024/01/25 13:02:11 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_structure.h"
#include "../ft_window.h"
#include "../ft_base.h"
#include <stdio.h>

t_offs ft_dfine_offset(char **map, int x1, int x2)
{
	t_offs 		offset;

	offset.down = 0;
	offset.up = 0;
	offset.right = 0;
	offset.left = 0;
	while (x2 - offset.left >= -1 && offset.left < SCREEN_X / (SPRITE_SIZE / 3))
		offset.left++;
	while (map[x1][x2 + offset.right + 2] != 0 && offset.right < SCREEN_X / (SPRITE_SIZE / 3))
		offset.right++;
	while (map[x1 + offset.down + 2] != 0 && offset.down < SCREEN_Y / (SPRITE_SIZE / 3))
		offset.down++;
	while (x1 - offset.up >= -1 && offset.up < SCREEN_Y / (SPRITE_SIZE / 3))
		offset.up++;
	return (offset);
}

void ft_to_start(t_offs offset, int *offset_cam, t_map *info)
{
	int	scr_x;
	int scr_y;

	scr_x = SCREEN_X / (SPRITE_SIZE / 3);
	scr_y = SCREEN_Y / (SPRITE_SIZE / 3);
	if ((offset.up + offset.down + 3) >= scr_y)
	{
		if (offset.down > scr_y / 2 && offset.up > scr_y / 2)
			offset_cam[0] = (scr_y - 3) / 2 * -1;
		else if (offset.up <= scr_y / 2)
			offset_cam[0] = -info->p_x1;
		else if (offset.down <= scr_y / 2)
			offset_cam[0] = -info->p_x1 + info->map_height * 3 - scr_y;
	}
	else
		offset_cam[0] = -info->p_x1;
	if ((offset.right + offset.left + 3) >= scr_x)
	{
		if (offset.right > scr_x / 2 && offset.left > scr_x / 2)
			offset_cam[1] = (scr_x - 3) / 2 * -1;
		else if (offset.left <= scr_x / 2)
			offset_cam[1] = -info->p_x2;
		else if (offset.right <= scr_x / 2)
			offset_cam[1] = -info->p_x2 + info->map_width * 3 - scr_x;
	}
	else
		offset_cam[1] = -info->p_x2;

	//printf("offset y : %d\n", offset_cam[0]);
	//printf("offset x : %d\n", offset_cam[1]);
}
