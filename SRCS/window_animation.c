/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:47:13 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/03 17:39:25 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/movement.h"

static inline void	_anim_ennemies(t_map *info, t_opps *bad)
{
	while (bad)
	{
		if (bad->state >= 0)
		{
			if (bad->state == 2)
				bad->state = 0;
			else
				++bad->state;
		}
		else
		{
			if (bad->state == -6)
			{
				_reset_chara(info, info->s_map, bad->x1, bad->x2);
				_lst_del_struct(bad);
			}
			else
				--bad->state;
		}
		bad = bad->next;
	}
}

static inline void	_anim_player(t_map *info)
{
	if (info->player_state <= 10 && info->player_state > 0
		&& info->proj->limit == -1)
		info->player_state++;
	else
		info->player_state = 0;
}

static inline void	_anim_proj(t_proj *proj)
{
	if (proj->limit == -1 && proj->shoot >= 1)
	{
		if (proj->shoot < 3)
			++proj->shoot;
	}
}

void	_refresh_anim(t_map *info, t_opps *bad, int *multi)
{
	_anim_ennemies(info, bad);
	_anim_player(info);
	_anim_proj(info->proj);
	++multi[0];
	if (multi[0] == SPEED_ANIM)
		multi[0] = 0;
}
