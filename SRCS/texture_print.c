/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:44:24 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 16:28:15 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/texture.h"

static void	_print_sprite(t_struct *g, t_block *block, int *pxl_cc, char c)
{
	int	*colors;
	int	pxl_y;
	int	pxl_x;
	int	i;

	colors = _sprite_stock(g->info, block, c);
	i = 0;
	pxl_y = pxl_cc[0];
	pxl_x = pxl_cc[1];
	while (colors[i])
	{
		if (colors[i] != -1)
			_mlx_pixel_put(g->img, pxl_x, pxl_y, colors[i]);
		++pxl_x;
		if (i % SPR_S == 0)
		{
			pxl_x = pxl_cc[1];
			++pxl_y;
		}
		++i;
	}
}

static void	_put_front(t_struct *g, t_map *info, t_block ***s_map, int *o_cam)
{
	int	x1;
	int	x2;
	int	pxl_cc[2];

	pxl_cc[0] = 0;
	x1 = info->p_x1 + o_cam[0] -1;
	while (++x1 - info->p_x1 + o_cam[0] < (SSIZE_Y / (SPR_S / 3)))
	{
		x2 = info->p_x2 + o_cam[1] - 1;
		pxl_cc[1] = 0;
		while (++x2 - (info->p_x2 + o_cam[1]) < (SSIZE_X / (SPR_S / 3)))
		{
			if (s_map[x1][x2]->nature == 'D' || s_map[x1][x2]->nature == 'P'
				|| s_map[x1][x2]->nature == 'x')
				_print_sprite(g, s_map[x1][x2], pxl_cc, s_map[x1][x2]->nature);
			pxl_cc[1] += SPR_S;
		}
		pxl_cc[0] += SPR_S;
	}
}

static void	_put_back(t_struct *g, t_map *info, t_block ***s_map, int *o_cam)
{
	int	x1;
	int	x2;
	int	pxl_cc[2];

	pxl_cc[0] = 0;
	x1 = info->p_x1 + o_cam[0] -1;
	while (++x1 - info->p_x1 + o_cam[0] < (SSIZE_Y / (SPR_S / 3)))
	{
		x2 = info->p_x2 + o_cam[1] - 1;
		pxl_cc[1] = 0;
		while (++x2 - (info->p_x2 + o_cam[1]) < (SSIZE_X / (SPR_S / 3)))
		{
			if (s_map[x1][x2]->nature == 'D' || s_map[x1][x2]->nature == 'P'
				|| s_map[x1][x2]->nature == 'x')
				_print_sprite(g, s_map[x1][x2], pxl_cc, '0');
			else
				_print_sprite(g, s_map[x1][x2], pxl_cc, s_map[x1][x2]->nature);
			pxl_cc[1] += SPR_S;
		}
		pxl_cc[0] += SPR_S;
	}
}

void	_texture_to_img(t_struct *g, t_map *info, t_block ***s_map)
{
	int	o_cam[2];

	_where_start(_edge_distance(s_map, info->p_x1, info->p_x2), o_cam, info);
	_put_back(g, info, info->s_map, o_cam);
	_put_front(g, info, info->s_map, o_cam);
}
