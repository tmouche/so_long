/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:44:24 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/05 15:47:45 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/texture.h"

static int	_spr_part(t_block ***s_map, int *cc, char c)
{
	int	off_x1;
	int	off_x2;

	if (c == 'D' || c == 'P' || c == 'x')
	{
		off_x1 = 0;
		while (s_map[cc[0] - off_x1][cc[1]]->type == c)
			++off_x1;
		off_x2 = 0;
		while (s_map[cc[0]][cc[1] - off_x2]->type == c)
			++off_x2;
		return (((off_x2 - 1) % 3 + SPR_S * ((off_x1 - 1) % 3)) * (SPR_S / 3));
	}
	else
		return ((cc[1] % 3 + SPR_S * (cc[0] % 3)) * (SPR_S / 3));
}

static inline void	_print_spr(t_struct *g, t_block *blk, int *pxl, int off)
{
	int		*colors;
	int		i;
	int		pxl_y;
	int		pxl_x;

	colors = _sprite_stock(g->info, blk, blk->type);
	pxl_y = pxl[0];
	pxl_x = pxl[1];
	i = 0;
	while (i < (SPR_S / 3) * (SPR_S / 3))
	{
		if (colors[off] != -1)
			_mlx_pixel_put(g->img, pxl_x, pxl_y, colors[off]);
		++i;
		++off;
		++pxl_x;
		if (i % (SPR_S / 3) == 0)
		{
			off += (SPR_S / 3) * 2;
			pxl_x = pxl[1];
			++pxl_y;
		}
	}
}

static void	_printer(t_struct *g, t_block ***s_map, int *cc, int *pxl_cc)
{
	if (s_map[cc[0]][cc[1]]->type == 'D' || s_map[cc[0]][cc[1]]->type == 'P'
		|| s_map[cc[0]][cc[1]]->type == 'x')
	{
		_print_spr(g, g->info->inv->empty, pxl_cc, _spr_part(s_map, cc, '0'));
		_print_spr(g, s_map[cc[0]][cc[1]], pxl_cc,
			_spr_part(s_map, cc, s_map[cc[0]][cc[1]]->type));
		if (s_map[cc[0]][cc[1]]->type == 'P' && g->info->unkillable == 1)
			_print_spr(g, g->info->inv->shield, pxl_cc, _spr_part(s_map, cc, 'P'));
	}
	else
		_print_spr(g, s_map[cc[0]][cc[1]], pxl_cc,
			_spr_part(s_map, cc, s_map[cc[0]][cc[1]]->type));
	pxl_cc[1] += SPR_S / 3;
	++cc[1];
}

static void	_put_sprite(t_struct *g, t_map *info, t_block ***s_map, int *o_cam)
{
	int	cc[2];
	int	pxl_cc[2];

	pxl_cc[0] = 0;
	cc[0] = info->p_x1 + o_cam[0];
	while (pxl_cc[0] < SSIZE_Y && s_map[cc[0]])
	{
		cc[1] = info->p_x2 + o_cam[1];
		pxl_cc[1] = 0;
		while (pxl_cc[1] < SSIZE_X && s_map[cc[0]][cc[1]])
			_printer(g, s_map, cc, pxl_cc);
		pxl_cc[0] += SPR_S / 3;
		++cc[0];
	}
}

void	_texture_to_img(t_struct *g, t_map *info, t_block ***s_map)
{
	int	o_cam[2];

	if (info->map_width * SPR_S > SSIZE_X || info->map_height * SPR_S > SSIZE_Y)
		_starter(_edge_distance(s_map, info->p_x1, info->p_x2), o_cam, info);
	else
	{
		o_cam[0] = -info->p_x1;
		o_cam[1] = -info->p_x2;
	}
	_put_sprite(g, info, info->s_map, o_cam);
}
