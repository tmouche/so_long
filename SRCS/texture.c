/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:44:24 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 15:54:35 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/texture.h"

static int _print_sprite(t_struct *glob, int *yx, int *p_yx, char c)
{
	int	*colors;
	int	lap;
	int offset;
	int p_x1_t;
	int p_x2_t;
	
	p_x1_t = p_yx[0];
	p_x2_t = p_yx[1];
	offset = _sprite_part(glob->info->s_map, yx[0], yx[1], c);
	colors = ft_colors(glob->info, c);
	if (!colors)
		return (-1);
	lap = 0;
	p_x2_t = (SPRITE_SIZE / 3) * p_x2_t;
	p_x1_t = (SPRITE_SIZE / 3) * p_x1_t;
	while (lap < ((SPRITE_SIZE / 3) * (SPRITE_SIZE / 3)))
	{
		if (colors[offset] != -1)
			ft_mlx_pixel_put(glob->img, p_x2_t, p_x1_t, colors[offset]);
		p_x2_t++;
		lap++;
		if (lap % (SPRITE_SIZE / 3) == 0)
		{
			offset += (SPRITE_SIZE / 3) * 2;
			p_x1_t++;
			p_x2_t -= SPRITE_SIZE / 3;
		}
		offset++;
	}
	return (0);
}

static void	_print_sprite(t_struct *g, t_block *block, int pxl_x1, int pxl_x2)
{
	int	*colors;

	colors = _sprite_stock(g->info, block, block->nature);
}

static void	_put_background(t_struct *g, t_map *info, t_block ***s_map, int *o_cam)
{
	int	x1;
	int	x2;
	int	pxl_x1;
	int	pxl_x2;

	x1 = info->p_x1 + o_cam[0] -1;
	while (++x1 - info->p_x1 + o_cam[0] < (SSIZE_Y / (SPR_S / 3)))
	{
		x2 = info->p_x2 + o_cam[1] - 1;
		while (++x2 - (info->p_x2 + o_cam[1]) < (SSIZE_X / (SPR_S / 3)))
		{
			if (s_map[x1][x2]->nature == 'D' || s_map[x1][x2]->nature == 'P'
				|| s_map[x1][x2]->nature == 'x')
				_print_sprite(g, s_map, pxl_x1, pxl_x2);
		}
	}
}

void	_texture_to_img(t_map *info, t_block ***s_map)
{
	int	yx[2];
	int	o_cam[2];

	_where_start(_edge_distance(s_map, info->p_x1, info->p_x2), o_cam, info);
	yx[0] = info->p_x1 + o_cam[0] - 1;
	while (++yx[0] - (info->p_x1 + o_cam[0]) < (SSIZE_Y / (SPR_S / 3)))
	{
		yx[1] = info->p_x2 + o_cam[1] - 1;
		while (++yx[1] - (info->p_x2 + o_cam[1]) < (SSIZE_X / (SPR_S / 3)))
		{
			
		}
	}
	
	
}

/*void	_texture_to_img(t_struct *g, t_block ***s_map, _Bool stop)
{
	int	yx[2];
	int	p_yx[2];
	int	o_cam[2];

	_where_start(_edge_distance(s_map, g->info->p_x1, g->info->p_x2), o_cam, g->info);
	yx[0] = g->info->p_x1 + o_cam[0] - 1;
	p_yx[0] = 0;
	while (++yx[0] - (g->info->p_x1 + o_cam[0]) < (SSIZE_Y / (SPR_S / 3)) && s_map[yx[0]])
	{
		yx[1] = g->info->p_x2 + o_cam[1] - 1;
		p_yx[1] = 0;
		while (++yx[1] - (g->info->p_x2 + o_cam[1]) < (SSIZE_X / (SPR_S / 3)) && s_map[yx[0]][yx[1]])
		{
			if (stop == 0)
			{
				if (s_map[yx[0]][yx[1]] == 'D' || s_map[yx[0]][yx[1]] == 'P' || s_map[yx[0]][yx[1]] == 'x')
					_print_sprite(g, yx, p_yx, '0');
				else
					_print_sprite(g, yx, p_yx, s_map[yx[0]][yx[1]]);
			}
			if (stop == 1)
				if (s_map[yx[0]][yx[1]] == 'D' || s_map[yx[0]][yx[1]] == 'P' || s_map[yx[0]][yx[1]] == 'x')
					ft_texture_img(g, yx, p_yx, s_map[yx[0]][yx[1]]);
			p_yx[1]++;
		}
		p_yx[0]++;
	}
	if (stop == 0)
		ft_texture(glob, map, 1);
}*/
