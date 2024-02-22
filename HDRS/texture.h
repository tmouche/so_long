/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:28:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 15:53:17 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_C
# define TEXTURE_C
# include "structure.h"

void	ft_texture(t_struct *glob, char **map, _Bool stop);
void	ft_update_anim(t_struct* glob);

int			*_sprite_stock(t_map *info, t_block *block, char c);

void 		_where_start(t_offs off, int *offset_cam, t_map *info);
t_offs		_edge_distance(t_block ***s_map, int x1, int x2);

void		_mlx_pixel_put(t_data *data, int x, int y, int color);
int			*_txt_sprite(t_struct *g, char *str);
t_colors	*_load_textures(t_struct *g);

#endif	