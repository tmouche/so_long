/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:32:04 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/03 16:35:04 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"

static int	*_sprite_anim_proj(t_colors *colors, int state)
{
	if (state == 1)
		return (colors->laser_1_r);
	if (state == 2)
		return (colors->laser_2_r);
	if (state == 3)
		return (colors->laser_3_r);
	else
		return (colors->laser_3_r);
}

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
	return (NULL);
}

static int	*_sprite_anim_player_r(t_colors *colors, int state)
{
	if (state != 0)
	{
		if (state <= 2 && state >= 0)
			return (colors->p_shoot1_r);
		else if (state <= 4)
			return (colors->p_shoot2_r);
		else if (state <= 6)
			return (colors->p_shoot3_r);
		else if (state <= 8)
			return (colors->p_shoot4_r);
		else if (state <= 10)
			return (colors->p_shoot5_r);
	}
	return (colors->p_r);
}

static int	*_sprite_anim_player_l(t_colors *colors, int state)
{
	if (state != 0)
	{
		if (state <= 2)
			return (colors->p_shoot1_l);
		else if (state <= 4)
			return (colors->p_shoot2_l);
		else if (state <= 6)
			return (colors->p_shoot3_l);
		else if (state <= 8)
			return (colors->p_shoot4_l);
		else if (state <= 10)
			return (colors->p_shoot5_l);
	}
	return (colors->p_l);
}

static int	*_sprite_animation(t_map *info, t_block *block)
{
	if (block->type == 'D')
		return (_sprite_anim_opps(info->colors, block->bad->state));
	else
	{
		if (info->vec == 1)
			return (_sprite_anim_player_r(info->colors, info->player_state));
		else
			return (_sprite_anim_player_l(info->colors, info->player_state));
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
		return (_sprite_anim_proj(info->colors, info->proj->shoot));
	else
		return (NULL);
}
