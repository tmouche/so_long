/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:56:51 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 13:48:23 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "structure.h"

void			ft_window(t_struct *glob);
int				ft_set_hex_color(char *src, int *i);
void 			ft_new_frame(t_struct *glob);
int 			ft_update(t_struct *glob);
void 			ft_to_start(t_offs offset, int *offset_cam, t_map *info);
t_offs 			ft_dfine_offset(char **map, int x1, int x2);

#endif