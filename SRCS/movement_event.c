/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:22 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/28 18:27:27 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/movement.h"

void	_kill_player(t_struct *g)
{
	_free_all(g, 5);
}

void	_collectible(t_map *info, int x1, int x2)
{
	while (x1 % 3 != 0)
		x1--;
	while (x2 % 3 != 0)
		x2--;
	info->collect--;
	_reset_chara(info->s_map, x1, x2);
}

void	_door(t_struct *g)
{
	_free_all(g, 5);
}
