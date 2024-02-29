/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:54:06 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/29 18:38:32 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/movement.h"
#include <unistd.h>

static int	_opps_check(t_struct *g, t_map *info, int (*cc)[2])
{
	char	c;
	int		i;
	
	i = 0;
	while (i < 3)
	{
		c = info->s_map[cc[i][0]][cc[i][1]]->nature;
		if (c != '0' && c != 'P')
			return (0);
		++i;
	}
	i = 0;
	while (i < 3)
	{
		c = info->s_map[cc[i][0]][cc[i][1]]->nature;
		if (c == 'P')
			_kill_player(g);
		++i;
	}
	return (1);
}

static int	_player_check(t_struct *g, t_map *info, int (*cc)[2], int limit)
{
	char	c;
	int		i;

	i = 0;
	while (i < limit)
	{
		c = info->s_map[cc[i][0]][cc[i][1]]->nature;
		if (c == '1' || c == '2' || (c == 'E' && info->collect != 0))
			return (0);
		++i;
	}
	i = 0;
	while (i < limit)
	{
		c = info->s_map[cc[i][0]][cc[i][1]]->nature;
		if (c == 'D')
			_kill_player(g);
		else if (c == 'C')
			_collectible(info, cc[i][0], cc[i][1]);
		else if (c == 'E')
			_door(g);
		++i;
	}
	return (1);
}

void	_ennemies(t_struct *g, t_map *info, t_opps *bad)
{
	int	check_l[3][2];

	while (bad)
	{
		if (bad->state >= 0)
		{
			if (bad->dir == 0)
				_check_v(bad->x1, bad->x2, bad->sens, check_l);
			else
				_check_h(bad->x1, bad->x2, bad->sens, check_l);
			if (_opps_check(g, info, check_l) == 0)
				bad->sens *= -1;
			else
				_move_opps(info, info->s_map, bad);
		}
		bad = bad->next;
	}
}

void	_player(t_struct *g, t_map *info, int o_x2)
{
	int	check_l[3][2];
	int	check_d[1][2];
	
	if (o_x2 != 0 && info->vec != o_x2)
		info->vec *= -1;
	_check_v(info->p_x1, info->p_x2, info->mv_y, check_l);
	if (_player_check(g, info, check_l, 3) == 0)
		return ;
	_check_h(info->p_x1, info->p_x2, info->mv_x, check_l);
	if (_player_check(g, info, check_l, 3) == 0)
		return ;
	if (info->mv_y != 0 && info->mv_x != 0)
	{
		_check_d(info->p_x1, info->p_x2, info->mv_y, info->mv_x, check_d);
		if (_player_check(g, info, (int (*)[2])check_d, 1) == 0)
			return ;
	}
	_move_player(info, info->mv_y, info->mv_x);
}