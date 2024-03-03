/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_projectile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:40:46 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/02 18:09:38 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/movement.h"
#include <X11/keysym.h>
#include <stdio.h>

void	_erase_proj(t_map *info, t_proj *laser, t_block ***s_map)
{
	int	i;

	i = 0;
	while (s_map[laser->x1][laser->x2 + i] == laser->laser)
	{
		s_map[laser->x1][laser->x2 + i] = info->empty;
		s_map[laser->x1 + 1][laser->x2 + i] = info->empty;
		s_map[laser->x1 + 2][laser->x2 + i] = info->empty;
		++i;
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

static void	_active_laser(t_block ***s_map, t_proj *laser)
{
	int	offset;

	offset = laser->x2 + (laser->limit * laser->o_x2);
	s_map[laser->x1][laser->x2 + offset] = laser->laser;
	s_map[laser->x1 + 1][laser->x2 + offset] = laser->laser;
	s_map[laser->x1 + 2][laser->x2 + offset] = laser->laser;
	++laser->limit;
}

static int	_laser_check(t_map *info, int (*cc)[2])
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (info->s_map[cc[i][0]][cc[i][1]] != info->empty
			|| !info->s_map[cc[i][0]][cc[i][1]]->bad)
			return (0);
		++i;
			
	}
	i = 0;
	while (i < 3)
	{
		if (info->s_map[cc[i][0]][cc[i][1]]->bad)
		{
			if (info->s_map[cc[i][0]][cc[i][1]]->bad->state >= 0)
				info->s_map[cc[i][0]][cc[i][1]]->bad->state = -1;
			return (0);
		}
		++i;
	}
	return (1);
}

void	_laser(t_map *info, t_proj *laser)
{
	int	check_l[3][2];

	while (laser->limit <= RANGE_LASER && laser->limit >= 0)
	{
		_check_v(laser->x1, laser->x2, laser->o_x2, check_l);
		if (_laser_check(info, check_l) == 1)
			_active_laser(info->s_map, laser);
		else
			laser->limit = -1;	
	}
	if (laser->limit > RANGE_LASER)
		laser->limit = -1;
	
	
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
