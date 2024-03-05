/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:22 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/05 15:21:45 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "../include/ft_printf/ft_printf.h"
#include "../HDRS/structure.h"
#include "../HDRS/movement.h"

void	_collectible(t_map *info, int x1, int x2)
{
	while (x1 % 3 != 0)
		x1--;
	while (x2 % 3 != 0)
		x2--;
	info->collect--;
	_reset_chara(info, info->s_map, x1, x2);
}

void	_this_is_the_end(t_struct *g, char c)
{
	if (c == 'E')
	{
		ft_printf("you reached the door with all collectibles gg...\n");
		ft_printf("but this tooks you %d steps :)\n", g->info->step / 3);
		g->info->freeze = 1;
	}
	else
	{
		ft_printf("GAME OVER ! An opps killed you loser :p\n");
		g->info->freeze = 1;
	}
	ft_printf("ESC to quit\n");
}
