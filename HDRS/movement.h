/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:54:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/28 18:25:16 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H
# include "structure.h"

void	_check_v(int x1, int x2, int o_x1, int **check);
void	_check_h(int x1, int x2, int o_x2, int **check);
void	_check_d(int x1, int x2, int m_x1, int m_x2, int **check);

void	_door(t_struct *g);
void	_kill_player(t_struct *g);
void	_collectible(t_map *info, int x1, int x2);

void	_move_opps(t_block ***s_map, t_opps *bad);
void	_move_player(t_map *info, int d_x1, int d_x2);

void	_reset_chara(t_block ***s_map, int x1, int x2);
void	_replace_chara(t_block ***s_map, int x1, int x2, char c);

void	_ennemies(t_struct *g, t_map *info, t_opps *bad);
void	_player(t_struct *g, t_map *info, int o_x2);

#endif
	