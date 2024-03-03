/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:44:24 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/03 17:23:02 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/texture.h"

static inline void	_print_sprite(t_struct *g, t_block *blk, int *pxl, char c)
{
	int	*colors;
	int	pxl_y;
	int	pxl_x;
	int	i;

	colors = _sprite_stock(g->info, blk, c);
	i = 0;
	pxl_y = pxl[0];
	pxl_x = pxl[1];
	while (i < SPR_S * SPR_S)
	{
		if (colors[i] != -1)
			_mlx_pixel_put(g->img, pxl_x, pxl_y, colors[i]);
		++pxl_x;
		if (++i % SPR_S == 0)
		{
			pxl_x = pxl[1];
			++pxl_y;
		}
	}
}

static inline void	_decider(t_struct *g, t_block ***s_map, int *cc, int *pxl)
{
	if ((s_map[cc[0]][cc[1]]->type == 'D' || s_map[cc[0]][cc[1]]->type == 'P')
		&& s_map[cc[0]][cc[1]] != s_map[cc[0] - 1][cc[1]])
	{
		_print_sprite(g, s_map[cc[0]][cc[1]], pxl, s_map[cc[0]][cc[1]]->type);
		cc[1] += 3;
		pxl[1] += SPR_S;
	}
	else
	{
		if (s_map[cc[0]][cc[1]]->type == 'x'
			&& s_map[cc[0]][cc[1]] != s_map[cc[0] - 1][cc[1]])
			_print_sprite(g, s_map[cc[0]][cc[1]],
				pxl, s_map[cc[0]][cc[1]]->type);
		++cc[1];
		pxl[1] += SPR_S / 3;
	}
}

static void	_put_front(t_struct *g, t_map *info, t_block ***s_map, int *o_cam)
{
	int	cc[2];
	int	pxl[2];

	pxl[0] = 0;
	cc[0] = info->p_x1 + o_cam[0];
	while (cc[0] - info->p_x1 + o_cam[0] < (SSIZE_Y / (SPR_S / 3))
		&& s_map[cc[0]])
	{
		cc[1] = info->p_x2 + o_cam[1];
		pxl[1] = 0;
		while (cc[1] - (info->p_x2 + o_cam[1]) < (SSIZE_X / (SPR_S / 3))
			&& s_map[cc[0]][cc[1]])
			_decider(g, g->info->s_map, cc, pxl);
		pxl[0] += SPR_S / 3;
		++cc[0];
	}
}

static void	_put_back(t_struct *g, t_map *info, t_block ***s_map, int *o_cam)
{
	int	x1;
	int	x2;
	int	pxl_cc[2];

	pxl_cc[0] = 0;
	x1 = info->p_x1 + o_cam[0];
	while (x1 - info->p_x1 + o_cam[0] < (SSIZE_Y / (SPR_S / 3)) && s_map[x1])
	{
		x2 = info->p_x2 + o_cam[1];
		pxl_cc[1] = 0;
		while (x2 - (info->p_x2 + o_cam[1]) < (SSIZE_X / (SPR_S / 3))
			&& s_map[x1][x2])
		{
			if (s_map[x1][x2]->type == 'D' || s_map[x1][x2]->type == 'P'
				|| s_map[x1][x2]->type == 'x')
				_print_sprite(g, s_map[x1][x2], pxl_cc, '0');
			else
				_print_sprite(g, s_map[x1][x2], pxl_cc, s_map[x1][x2]->type);
			pxl_cc[1] += SPR_S;
			x2 += 3;
		}
		pxl_cc[0] += SPR_S;
		x1 += 3;
	}
}

void	_texture_to_img(t_struct *g, t_map *info, t_block ***s_map)
{
	int	o_cam[2];

	_where_start(_edge_distance(s_map, info->p_x1, info->p_x2), o_cam, info);
	_put_back(g, info, info->s_map, o_cam);
	_put_front(g, info, info->s_map, o_cam);
}
