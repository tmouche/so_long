/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:54:06 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 15:22:11 by tmouche          ###   ########.fr       */
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
		c = info->s_map[cc[i][0]][cc[i][1]]->type;
		if (c != '0' && c != 'P')
			return (0);
		else if (c == 'P' && info->unkillable == 1)
			return (0);
		++i;
	}
	i = 0;
	while (i < 3)
	{
		c = info->s_map[cc[i][0]][cc[i][1]]->type;
		if (c == 'P')
		{
			_this_is_the_end(g, 'D');
			return (0);
		}
		++i;
	}
	return (1);
}

static int	_player_check(t_struct *g, t_map *info, int (*cc)[2], int limit)
{
	char	c;
	int		i;

	i = -1;
	while (++i < limit)
	{
		c = info->s_map[cc[i][0]][cc[i][1]]->type;
		if (c == '1' || c == '2' || (c == 'E' && info->collect != 0))
			return (0);
	}
	i = -1;
	while (++i < limit)
	{
		c = info->s_map[cc[i][0]][cc[i][1]]->type;
		if (c == 'C')
			_collectible(info, cc[i][0], cc[i][1]);
		else if (c == 'D' || c == 'E')
		{
			_this_is_the_end(g, c);
			return (0);
		}
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

void	_player(t_struct *g, t_map *info)
{
	int	check_l[3][2];
	int	check_d[1][2];
	int	mv[2];

	if (info->proj->shoot != 0)
		return ;
	if (info ->mv_x != 0 && info->vec != info->mv_x)
		info->vec *= -1;
	_check_v(info->p_x1, info->p_x2, info->mv_y, check_l);
	if (_player_check(g, info, check_l, 3) == 0)
		return ;
	_check_h(info->p_x1, info->p_x2, info->mv_x, check_l);
	if (_player_check(g, info, check_l, 3) == 0)
		return ;
	if (info->mv_y != 0 && info->mv_x != 0)
	{
		mv[0] = info->mv_y;
		mv[1] = info->mv_x;
		_check_d(info->p_x1, info->p_x2, mv, check_d);
		if (_player_check(g, info, (int (*)[2])check_d, 1) == 0)
			return ;
	}
	_move_player(g, info, info->mv_y, info->mv_x);
}
