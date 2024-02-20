/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:32:04 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 13:22:05 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_window.h"
#include "../ft_base.h"
#include "../ft_texture.h"

void	ft_update_anim(t_struct* glob)
{
	if (glob->info->proj->i == 0 && glob->info->player_state == 0
		&& glob->info->proj->shoot == 0)
		return ;
	if (glob->info->player_state <= 10 && glob->info->proj->shoot != 0)
		glob->info->player_state++;
	else
	{
		glob->info->player_state = 0;
		glob->info->proj->shoot = 0;
	}
}

static int	*ft_which_sprite(t_map *info, t_opps *bad ,char c)
{
	if (c == 'D')
	{
		if (bad->state == 0)
			return (info->colors->opps_low);
		if (bad->state == 1)
			return (info->colors->opps_mid);
		if (bad->state == 2)
			return (info->colors->opps_top);
	}
	else
	{
		if (info->vec == 1)
		{
			if (info->player_state != 0)
			{
				if (info->player_state <= 2 && info->player_state >= 0)
					return (info->colors->player_shoot1_right);
				else if (info->player_state <= 4)
					return (info->colors->player_shoot2_right);
				else if (info->player_state <= 6)
					return (info->colors->player_shoot3_right);
				else if (info->player_state <= 8)
					return (info->colors->player_shoot4_right);
				else if (info->player_state <= 10)
					return (info->colors->player_shoot5_right);
			}
			return (info->colors->player_right);
		}
		else
		{
			if (info->player_state != 0)
			{
				if (info->player_state <= 2)
					return (info->colors->player_shoot1_left);
				else if (info->player_state <= 4)
					return (info->colors->player_shoot2_left);
				else if (info->player_state <= 6)
					return (info->colors->player_shoot3_left);
				else if (info->player_state <= 8)
					return (info->colors->player_shoot4_left);
				else if (info->player_state <= 10)
					return (info->colors->player_shoot5_left);
			}
			return (info->colors->player_left);
		}
	}
	return (NULL);
}

void	ft_struct_charger_anim(t_colors *colors)
{
	colors->player_shoot1_left = (ft_blocks("graph/player_shoot1_left.txt"));
	colors->player_shoot2_left = (ft_blocks("graph/player_shoot2_left.txt"));
	colors->player_shoot3_left = (ft_blocks("graph/player_shoot3_left.txt"));
	colors->player_shoot4_left = (ft_blocks("graph/player_shoot4_left.txt"));
	colors->player_shoot5_left = (ft_blocks("graph/player_shoot5_left.txt"));
	colors->player_shoot1_right = (ft_blocks("graph/player_shoot1_right.txt"));
	colors->player_shoot2_right = (ft_blocks("graph/player_shoot2_right.txt"));
	colors->player_shoot3_right = (ft_blocks("graph/player_shoot3_right.txt"));
	colors->player_shoot4_right = (ft_blocks("graph/player_shoot4_right.txt"));
	colors->player_shoot5_right = (ft_blocks("graph/player_shoot5_right.txt"));
	colors->explosion_1 = ft_blocks("graph/explosion_1.txt");
	colors->explosion_2 = ft_blocks("graph/explosion_2.txt");
	colors->explosion_3 = ft_blocks("graph/explosion_3.txt");
	colors->explosion_4 = ft_blocks("graph/explosion_4.txt");
}

void	ft_struct_charger(t_colors *colors)
{
	colors->player_left = ft_blocks("graph/player_left.txt");
	colors->player_right = ft_blocks("graph/player_right.txt");
	colors->opps_low = ft_blocks("graph/opps_low.txt");
	colors->opps_mid = ft_blocks("graph/opps_mid.txt");
	colors->opps_top = ft_blocks("graph/opps_top.txt");
	colors->collect = ft_blocks("graph/collec.txt");
	colors->door = ft_blocks("graph/door.txt");
	colors->empty = ft_blocks("graph/empty.txt");
	colors->wall = ft_blocks("graph/wall.txt");
	colors->proj = ft_blocks("graph/proj.txt");
	ft_struct_charger_anim(colors);
}

int	*ft_colors(t_map *info, t_opps *bad, char c)
{
	if (c == '1' || c == '2')
		return (info->colors->wall);
	if (c == 'D' || c == 'P')
		return (ft_which_sprite(info, bad, c));
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
