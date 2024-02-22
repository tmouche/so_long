/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:32:04 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 15:51:49 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"

static int	*_sprite_anim_opps(t_colors *colors, int state)
{
	if (state >= 0)
	{
		if (state == 0)
			return (colors->opps_bot);
		if (state == 1)
			return (colors->opps_mid);
		if (state == 2)
			return (colors->opps_top);
	}
	else
	{
		if (state == -1)
			return (colors->explosion_1);
		if (state == -2)
			return (colors->explosion_2);
		if (state == -3)
			return (colors->explosion_3);
		if (state == -4)
			return (colors->explosion_4);
		if (state == -5)
			return (colors->explosion_5);
		if (state == -6)
			return (colors->explosion_6);
	}
}

static int	*_sprite_anim_player_right(t_colors *colors, int state)
{
	if (state != 0)
	{
		if (state <= 2 && state >= 0)
			return (colors->player_shoot1_right);
		else if (state <= 4)
			return (colors->player_shoot2_right);
		else if (state <= 6)
			return (colors->player_shoot3_right);
		else if (state <= 8)
			return (colors->player_shoot4_right);
		else if (state <= 10)
			return (colors->player_shoot5_right);
	}
	return (colors->player_right);
}

static int	*_sprite_anim_player_left(t_colors *colors, int state)
{
	if (state != 0)
	{
		if (state <= 2)
			return (colors->player_shoot1_left);
		else if (state <= 4)
			return (colors->player_shoot2_left);
		else if (state <= 6)
			return (colors->player_shoot3_left);
		else if (state <= 8)
			return (colors->player_shoot4_left);
		else if (state <= 10)
			return (colors->player_shoot5_left);
	}
	return (colors->player_left);
}

static int	*_sprite_animation(t_map *info, t_block *block)
{
	if (block->nature = 'D')
		return (_sprite_anim_opps(info->colors, block->bad->state));
	else
	{
		if (info->vec == 1)
			return (_sprite_anim_player_right(info->colors, info->player_state));
		else
			return (_sprite_anim_player_left(info->colors, info->player_state));
	}
}

int	*_sprite_stock(t_map *info, t_block *block, char c)
{
	if (c == '1' || c == '2')
		return (info->colors->wall);
	if (c == 'D' || c == 'P')
		return (_sprite_animation(info, block));
	if (c == 'E')
		return (info->colors->door);
	if (c == '0')
		return (info->colors->empty);
	if (c == 'C')
		return (info->colors->collect);
	if (c == 'x')
		return (info->colors->proj);
	else
		return (NULL);
}
