/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_projectile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:40:46 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/01 14:55:35 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include <X11/keysym.h>

void	_define_projectile(t_map *info, t_proj *proj, int keycode)
{
	proj->limit = 12;
	proj->shoot = 1;
	if (keycode == XK_Left || keycode == XK_Right)
	{
		proj->o_x2 = keycode % 10 - 2;
		proj->x1 = info->p_x1 + 1;
		proj->x2 = info->p_x2 + (keycode % 10 * 2 - 3);
	}
	else if (keycode == XK_Down || keycode == XK_Up)
	{
		proj->o_x1 = keycode % 10 - 3;
		proj->x1 = info->p_x1 + (keycode % 10 * 2 - 5);
		proj->x2 = info->p_x2 + 1;
	}
	if (proj->o_x2 != 0 && info->vec != proj->o_x2)
		info->vec *= -1;
	if (info->s_map[proj->x1][proj->x2] == info->empty)
		info->s_map[proj->x1][proj->x2] = info->b_proj;
}

void	_throw_proj(t_map *info, t_proj *proj, t_block ***s_map)
{
	_Bool	stop;
	
	stop = 0;
	if (s_map[proj->x1][proj->x2] == info->b_proj)
		s_map[proj->x1][proj->x2] = info->empty;
	proj->x1 += 1 * proj->o_x1;
	proj->x2 += 1 * proj->o_x2;
	if (s_map[proj->x1][proj->x2] == info->empty)
		s_map[proj->x1][proj->x2] = info->b_proj;
	else
	{
		if(s_map[proj->x1][proj->x2]->type == 'D')
			s_map[proj->x1][proj->x2]->bad->state = -1;
		stop = 1;
	}
	if (++proj->i == proj->limit + 1 || stop == 1)
	{
		proj->limit = 0;
		proj->i = 0;
		if (s_map[proj->x1][proj->x2] == info->b_proj)
			s_map[proj->x1][proj->x2] = info->empty;
		proj->o_x1 = 0;
		proj->o_x2 = 0;
	}
}
