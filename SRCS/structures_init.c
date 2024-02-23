/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:47 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 11:55:17 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"

static void	_init_t_colors_bis(t_ colors *colors)
{
	colors->explosion_4 = NULL;
	colors->explosion_5 = NULL;
	colors->explosion_6 = NULL;
}

void	_init_t_colors(t_colors *colors)
{
	colors->p_l = NULL;
	colors->p_r = NULL;
	colors->opps_bot = NULL;
	colors->opps_mid = NULL;
	colors->opps_top = NULL;
	colors->collect = NULL;
	colors->door = NULL;
	colors->empty = NULL;
	colors->wall = NULL;
	colors->proj = NULL;
	colors->p_shoot1_l = NULL;
	colors->p_shoot2_l = NULL;
	colors->p_shoot3_l = NULL;
	colors->p_shoot4_l = NULL;
	colors->p_shoot5_l = NULL;
	colors->p_shoot1_r = NULL;
	colors->p_shoot2_r = NULL;
	colors->p_shoot3_r = NULL;
	colors->p_shoot4_r = NULL;
	colors->p_shoot5_r = NULL;
	colors->explosion_1 = NULL;
	colors->explosion_2 = NULL;
	colors->explosion_3 = NULL;
	_init_t_colors_bis(colors);
}

void	_init_t_map(t_map *info, int x1, int x2, int collect)
{
	static t_proj	proj;

	info->map_width = x2;
	info->map_height = x1;
	info->collect = collect;
	info->step = 0;
	info->vec = 1;
	info->player_state = 0;
	info->mv_x = 0;
	info->mv_y = 0;
	info->proj = &proj;
	info->proj->limit = 0;
	info->proj->i = 0;
	info->proj->o_x1 = 0;
	info->proj->o_x2 = 0;
}

