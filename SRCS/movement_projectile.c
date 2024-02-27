/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_projectile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:40:46 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/27 18:38:18 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include <X11/keysym.h>

void	ft_set_proj(t_map *info, int keycode)
{
	info->proj->limit = 12;
	info->proj->shoot = 1;
	if (keycode == XK_Left || keycode == XK_Right)
	{
		info->proj->o_x2 = keycode % 10 - 2;
		info->proj->x1 = info->p_x1 + 1;
		info->proj->x2 = info->p_x2 + (keycode % 10 * 2 - 3);
	}
	else if (keycode == XK_Down || keycode == XK_Up)
	{
		info->proj->o_x1 = keycode % 10 - 3;
		info->proj->x1 = info->p_x1 + (keycode % 10 * 2 - 5);
		info->proj->x2 = info->p_x2 + 1;
	}
	if (info->proj->o_x2 != 0 && info->vec != info->proj->o_x2)
		info->vec *= -1;
	if (info->s_map[info->proj->x1][info->proj->x2] == '0')
		info->s_map[info->proj->x1][info->proj->x2] = 'x';
}

void	ft_projectile(t_map *info, t_proj *proj, char **map)
{
	_Bool	stop;
	
	stop = 0;
	if (map[proj->x1][proj->x2] == 'x')
		map[proj->x1][proj->x2] = '0';
	proj->x1 += 1 * proj->o_x1;
	proj->x2 += 1 * proj->o_x2;
	if (map[proj->x1][proj->x2] == '0')
		map[proj->x1][proj->x2] = 'x';
	else
	{
		if(map[proj->x1][proj->x2] == 'D')
			_kill_opps(*(info->bad), proj->x1, proj->x2);
		stop = 1;
	}
	if (++proj->i == proj->limit + 1 || stop == 1)
	{
		proj->limit = 0;
		proj->i = 0;
		if (map[proj->x1][proj->x2] == 'x')
			map[proj->x1][proj->x2] = '0';
		proj->o_x1 = 0;
		proj->o_x2 = 0;
	}
}
