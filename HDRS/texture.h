/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:28:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/03 17:08:18 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "structure.h"

void		_texture_to_img(t_struct *g, t_map *info, t_block ***s_map);

int			*_sprite_stock(t_map *info, t_block *block, char c);

void		_where_start(t_offs off, int *offset_cam, t_map *info);
t_offs		_edge_distance(t_block ***s_map, int x1, int x2);

void		_mlx_pixel_put(t_data *data, int x, int y, int color);
void		_load_textures(t_struct *g);

#endif