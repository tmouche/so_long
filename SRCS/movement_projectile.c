/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_projectile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:40:46 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 15:03:51 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/movement.h"
#include <X11/keysym.h>

void	_erase_proj(t_map *info, t_proj *laser, t_block ***s_map)
{
	int	i;

	i = 0;
	if (info->vec == 1)
	{
		while (s_map[laser->x1][laser->x2 + i] == laser->laser)
		{
			s_map[laser->x1][laser->x2 + i] = info->inv->empty;
			s_map[laser->x1 + 1][laser->x2 + i] = info->inv->empty;
			s_map[laser->x1 + 2][laser->x2 + i] = info->inv->empty;
			++i;
		}
	}
	else
	{
		while (s_map[laser->x1][laser->x2 + i] == laser->laser)
		{
			s_map[laser->x1][laser->x2 + i] = info->inv->empty;
			s_map[laser->x1 + 1][laser->x2 + i] = info->inv->empty;
			s_map[laser->x1 + 2][laser->x2 + i] = info->inv->empty;
			--i;
		}
	}
}

void	_define_projectile(t_map *info, t_proj *proj, int keycode)
{
	if (proj->limit != -1)
		return ;
	proj->limit = 0;
	proj->shoot = 1;
	proj->o_x2 = keycode % 10 - 2;
	proj->x1 = info->p_x1;
	if (keycode == XK_Left)
		proj->x2 = info->p_x2 - 1;
	else if (keycode == XK_Right)
		proj->x2 = info->p_x2 + 3;
	if (info->vec != proj->o_x2)
		info->vec *= -1;
}

static void	_active_laser(t_block ***s_map, t_proj *proj)
{
	int	offset;

	offset = proj->limit * proj->o_x2;
	s_map[proj->x1][proj->x2 + offset] = proj->laser;
	s_map[proj->x1 + 1][proj->x2 + offset] = proj->laser;
	s_map[proj->x1 + 2][proj->x2 + offset] = proj->laser;
	++proj->limit;
}

static int	_laser_check(t_map *info, int (*cc)[2])
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (info->s_map[cc[i][0]][cc[i][1]] != info->inv->empty)
			if (info->s_map[cc[i][0]][cc[i][1]]->bad == NULL)
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
	int			check_l[3][2];

	if (laser->limit <= RANGE_LASER && laser->limit >= 0)
	{
		_check_h(info->p_x1, info->p_x2 + (laser->limit * laser->o_x2),
			laser->o_x2, check_l);
		if (_laser_check(info, check_l) == 1)
			_active_laser(info->s_map, laser);
		else
			laser->limit = -1;
	}
	if (laser->limit > RANGE_LASER)
		laser->limit = -1;
	if (laser->limit == -1)
		info->player_state = 1;
}
