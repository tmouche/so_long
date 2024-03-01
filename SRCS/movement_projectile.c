/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_projectile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:40:46 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/01 19:07:38 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/movement.h"
#include <X11/keysym.h>
#include <stdio.h>

void	_erase_proj(t_map *info, t_proj *proj, t_block ***s_map)
{
	while (s_map[proj->x1][proj->x2] == proj->laser)
	{
		_reset_chara(info, s_map, proj->x1, proj->x2);
		proj->x2 += 3;
	}
}

void	_define_projectile(t_map *info, t_proj *proj, int keycode)
{
	proj->limit = 0;
	proj->shoot = 1;
	proj->o_x2 = keycode % 10 - 2;
	proj->x1 = info->p_x1;
	if (keycode == XK_Left)
		proj->x2 = info->p_x2 - 1;	
	else if (keycode == XK_Right)
		proj->x2 = info->p_x2 + 3;	
	if (proj->o_x2 != 0 && info->vec != proj->o_x2)
		info->vec *= -1;
}

void	_throw_proj(t_proj *proj, t_block ***s_map)
{
	int	offset;

	offset = proj->x2 + (proj->limit * proj->o_x2);
	
	_replace_chara(s_map, proj->laser, proj->x1, offset);
	if (proj->limit >= RANGE_LASER)
	{
		proj->limit = -1;
		proj->shoot = 0;
	}
	else
		proj->limit += 3;
}

/*void	_erase_proj(t_map *info, t_proj *proj, t_block ***s_map)
{
	while (s_map[proj->x1][proj->x2] == info->b_proj)
	{
		s_map[proj->x1][proj->x2] = info->empty;
		++proj->x2;
	}
}

void	_throw_proj(t_map *info, t_proj *proj, t_block ***s_map)
{
	if (s_map[proj->x1][proj->x2 + proj->limit] == info->empty)
	{
		s_map[proj->x1][proj->x2 + proj->limit] = info->b_proj;
		if (proj->limit == RANGE_LASER)
			proj->limit = -1;
		++proj->limit;
	}
	else
	{
		if (s_map[proj->x1][proj->x2]->bad)
			if (s_map[proj->x1][proj->x2]->bad->state >= 0)
				s_map[proj->x1][proj->x2]->bad->state = -1;
		proj->limit = -1;
	}
}*/

/*void	_throw_proj(t_map *info, t_proj *proj, t_block ***s_map)
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
}*/
