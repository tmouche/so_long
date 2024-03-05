/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:13:03 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/05 18:22:59 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "../HDRS/structure.h"
#include "../HDRS/movement.h"
#include "../HDRS/window.h"
#include "../HDRS/texture.h"
#include <stdio.h>

int	_key_release(int keycode, t_struct *g)
{
	if (keycode == 'x')
		g->info->unkillable *= -1;
	if (keycode == 'w')
		g->info->mv_y = 0;
	if (keycode == 'a')
		g->info->mv_x = 0;
	if (keycode == 's')
		g->info->mv_y = 0;
	if (keycode == 'd')
		g->info->mv_x = 0;
	if ((keycode == 65361 || keycode == 65363) && g->info->proj->limit == -1
		&& g->info->unkillable != 1 && g->info->proj->shoot == 0)
		_define_projectile(g->info, g->info->proj, keycode);
	if ((keycode == 65362 || keycode == 65364) && g->info->proj->limit == -1
		&& g->info->unkillable != 1)
		_knife(g->info, g->info->s_map, keycode);
	return (0);
}

int	_key_press(int keycode, t_struct *g)
{
	if (keycode == 'w')
		g->info->mv_y = -1;
	if (keycode == 'a')
		g->info->mv_x = -1;
	if (keycode == 's')
		g->info->mv_y = 1;
	if (keycode == 'd')
		g->info->mv_x = 1;
	if (keycode == 65307)
		_free_all(g, 5);
	return (0);
}
