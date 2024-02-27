/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:48:03 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/27 18:38:58 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_structure.h"
#include "../ft_movement.h"
#include "../ft_window.h"
#include <stdio.h>

static int	ft_check_char(char c)
{
	if (c == 'D')
		return (-2);
	if (c == '2' || c == '1')
		return (-1);
	if (c == 'E')
		return (0);
	if (c == '0')
		return (1);
	if (c == 'C')
		return (2);
	return (4);
}

static int	ft_check_diag(t_map *info, int (*check)[2])
{
	if (ft_check_char(info->map[check[0][0]][check[0][1]]) < 0)
		return (0);
	return (2);
}

static int	ft_player_check(t_map *info, int (*check)[2])
{
	int	i;
	int	res;

	i = 0;
	while (i < 3)
	{
		res = ft_check_char(info->map[check[i][0]][check[i][1]]);
		if (res < 0)
			return (res);
		if (res == 2)
		{
			res = ft_is_a_collect(info, check, -1);
			break;
		}
		/*if (res == 0)
			ft_is_a_door(info, check, i);*/
		i++;
		res = 2;
	}
	return (res);
}

static int	ft_opps_check(t_map *info, int (*check)[2])
{
	int	i;
	
	i = 0;
	while (i < 3)
	{
		if (info->map[check[i][0]][check[i][1]] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_ennemies(t_map *info, t_opps *bad)
{
	int	res;

	while (bad)
	{
		if (bad->state >= 0)
		{
			if (bad->dir == 0)
				res = ft_opps_check(info, ft_chk_v(bad->x1, bad->x2, bad->sens));
			else
				res = ft_opps_check(info, ft_chk_h(bad->x1, bad->x2, bad->sens));
			if (res != 1)
			{
				bad->sens *= -1;
				if (bad->dir == 0)
					res = ft_opps_check(info, ft_chk_v(bad->x1, bad->x2, bad->sens));
				else
					res = ft_opps_check(info, ft_chk_h(bad->x1, bad->x2, bad->sens));
			}
			if (res == 1)
				ft_move_opps(bad, info->map);
		}
		bad = bad->next;
	}
}

int	ft_player(t_map *info, int o_x1, int o_x2)
{
	int checker;
	
	checker = 0;
	if (o_x2 != 0 && info->vec != o_x2)
		info->vec *= -1;
	if (ft_player_check(info, ft_chk_v(info->p_x1, info->p_x2, info->mv_y)) == 2)
		checker++;
	if (ft_player_check(info, ft_chk_h(info->p_x1, info->p_x2, info->mv_x)) == 2)
		checker++;
	if (info->mv_y != 0 && info->mv_x != 0)
		if (ft_check_diag(info, ft_chk_d(info->p_x1, info->p_x2, info->mv_y, info->mv_x)) != 2)
			checker--;
	if (checker == 2)
		ft_move_player(info, info->mv_y, info->mv_x);
	return (0);	
}