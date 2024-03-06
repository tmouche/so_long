/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:47 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 11:25:47 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "../HDRS/structure.h"
#include <unistd.h>

void	_init_t_map(t_map *info, int x1, int x2, int collect)
{
	static t_proj	proj;
	static t_block	laser;

	info->freeze = 0;
	info->unkillable = 1;
	info->map_width = x2;
	info->map_height = x1;
	info->collect = collect;
	info->step = 0;
	info->vec = 1;
	info->player_state = 0;
	info->mv_x = 0;
	info->mv_y = 0;
	info->proj = &proj;
	proj.limit = -1;
	proj.o_x2 = 0;
	proj.laser = &laser;
	laser.bad = NULL;
	laser.type = 'x';
}

static inline void	_init_map_block_bis(t_map *info)
{
	static t_block	collect;
	static t_block	player;
	static t_block	shield;

	info->inv->collect = &collect;
	collect.bad = NULL;
	collect.type = 'C';
	info->inv->player = &player;
	player.bad = NULL;
	player.type = 'P';
	info->inv->shield = &shield;
	shield.bad = NULL;
	shield.type = 's';
}

void	_init_map_block(t_map *info)
{
	static t_invent	inventory;
	static t_block	empty;
	static t_block	wall_out;
	static t_block	wall_in;
	static t_block	exit;

	info->inv = &inventory;
	inventory.empty = &empty;
	empty.bad = NULL;
	empty.type = '0';
	inventory.wall_out = &wall_out;
	wall_out.bad = NULL;
	wall_out.type = '1';
	inventory.wall_in = &wall_in;
	wall_in.bad = NULL;
	wall_in.type = '2';
	inventory.exit = &exit;
	exit.bad = NULL;
	exit.type = 'E';
	_init_map_block_bis(info);
}
