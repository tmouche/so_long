/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:54:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 13:48:27 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H
# include "structure.h"

int		ft_is_a_collect(t_map *info, int (*k)[2], int i);
void	ft_reset_chara(char **map, int x1, int x2);
void	ft_replace_chara(char **map, int x1, int x2, char c);
void	ft_move_player(t_map *info, int d_x1, int d_x2);
void	ft_move_opps(t_opps *bad, char **map);
char	*ft_give_step(int collec, int step);
int		ft_player(t_map *info, int o_x1, int o_x2);
void	ft_ennemies(t_map *info, t_opps *bad);
int		(*ft_chk_v(int x1, int x2, int o_x1))[2];
int		(*ft_chk_h(int x1, int x2, int o_x2))[2];
int		(*ft_chk_d(int x1, int x2, int m_x1, int m_x2))[2];
void	ft_set_proj(t_map *info, int keycode);
void	ft_projectile(t_map *info, t_proj *proj, char **map);

#endif
	