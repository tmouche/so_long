/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:47:38 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 16:27:59 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"

static void	_define_off_x(t_offs off, int *offset_cam, t_map *info)
{
	int	scr_x;

	scr_x = SSIZE_X / (SPR_S / 3);
	if (off.r > scr_x / 2 && off.l > scr_x / 2)
		offset_cam[1] = (scr_x - 3) / 2 * -1;
	else if (off.l <= scr_x / 2)
		offset_cam[1] = -info->p_x2;
	else if (off.r <= scr_x / 2)
		offset_cam[1] = -info->p_x2 + info->map_width * 3 - scr_x;
}

static void	_define_off_y(t_offs off, int *offset_cam, t_map *info)
{
	int	scr_y;

	scr_y = SSIZE_Y / (SPR_S / 3);
	if (off.d > scr_y / 2 && off.u > scr_y / 2)
		offset_cam[0] = (scr_y - 3) / 2 * -1;
	else if (off.u <= scr_y / 2)
		offset_cam[0] = -info->p_x1;
	else if (off.d <= scr_y / 2)
		offset_cam[0] = -info->p_x1 + info->map_height * 3 - scr_y;
}

t_offs	_edge_distance(t_block ***s_map, int x1, int x2)
{
	t_offs	off;

	off.d = 0;
	off.u = 0;
	off.r = 0;
	off.l = 0;
	while (x2 - off.l >= -1 && off.l < SSIZE_X / (SPR_S / 3))
		off.l++;
	while (s_map[x1][x2 + off.r + 2] != 0 && off.r < SSIZE_X / (SPR_S / 3))
		off.r++;
	while (s_map[x1 + off.d + 2] != 0 && off.d < SSIZE_Y / (SPR_S / 3))
		off.d++;
	while (x1 - off.u >= -1 && off.u < SSIZE_Y / (SPR_S / 3))
		off.u++;
	return (off);
}

void	_where_start(t_offs off, int *offset_cam, t_map *info)
{
	if ((off.u + off.d + 3) >= SSIZE_Y / (SPR_S / 3))
		_define_off_y(off, offset_cam, info);
	else
		offset_cam[0] = -info->p_x1;
	if ((off.r + off.l + 3) >= SSIZE_X / (SPR_S / 3))
		_define_off_x(off, offset_cam, info);
	else
		offset_cam[1] = -info->p_x2;
}
