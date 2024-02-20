/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:44:24 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 11:34:49 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_structure.h"
#include "../ft_texture.h"
#include "../ft_base.h"
#include "../ft_window.h"
#include <stdio.h>

static int ft_which_x1(char **map, int x1, int x2, char c)
{
	int	offset;
	
	offset = 1;
	while (map[x1 - offset][x2] == c)
		offset++;
	return (offset - 1);
}

static int ft_which_x2(char **map, int x1, int x2, char c)
{
	int	offset;
	
	offset = 0;
	while (map[x1][x2 - offset] == c)
		offset++;
	return (offset - 1);
}

static int	ft_texture_part(char **map, int x1, int x2, char c)
{
	int	temp_x1;
	int	temp_x2;
	
	temp_x1 = x1;
	temp_x2 = x2;
	if (c == 'D' || c == 'P')
	{
		x1 = ft_which_x1(map, temp_x1, temp_x2, c);
		x2 = ft_which_x2(map, temp_x1, temp_x2, c);
	}
	if (c == 'x')
	{
		x1 = 1;
		x2 = 1;
	}
	return ((x2 % 3 + SPRITE_SIZE * (x1 % 3)) * (SPRITE_SIZE / 3));
}

static int ft_texture_img(t_struct *glob, int *yx, int *p_yx, char c)
{
	int	*colors;
	int	lap;
	int offset;
	int p_x1_t;
	int p_x2_t;
	
	p_x1_t = p_yx[0];
	p_x2_t = p_yx[1];
	offset = ft_texture_part(glob->info->map, yx[0], yx[1], c);
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

void	ft_texture(t_struct *glob, char **map, _Bool stop)
{
	int	yx[2];
	int	p_yx[2];
	int	offset[2];

	ft_to_start(ft_dfine_offset(map, glob->info->p_x1, glob->info->p_x2), offset, glob->info);
	yx[0] = glob->info->p_x1 + offset[0] - 1;
	p_yx[0] = 0;
	while (++yx[0] - (glob->info->p_x1 + offset[0]) < (SCREEN_Y / (SPRITE_SIZE / 3)) && map[yx[0]])
	{
		yx[1] = glob->info->p_x2 + offset[1] - 1;
		p_yx[1] = 0;
		while (++yx[1] - (glob->info->p_x2 + offset[1]) < (SCREEN_X / (SPRITE_SIZE / 3)) && map[yx[0]][yx[1]])
		{
			if (stop == 0)
			{
				if (map[yx[0]][yx[1]] == 'D' || map[yx[0]][yx[1]] == 'P' || map[yx[0]][yx[1]] == 'x')
					ft_texture_img(glob, yx, p_yx, '0');
				else
					ft_texture_img(glob, yx, p_yx, map[yx[0]][yx[1]]);
			}
			if (stop == 1)
				if (map[yx[0]][yx[1]] == 'D' || map[yx[0]][yx[1]] == 'P' || map[yx[0]][yx[1]] == 'x')
					ft_texture_img(glob, yx, p_yx, map[yx[0]][yx[1]]);
			p_yx[1]++;
		}
		p_yx[0]++;
	}
	if (stop == 0)
		ft_texture(glob, map, 1);
}
