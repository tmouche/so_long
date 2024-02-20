/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:28:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 13:48:20 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_C
# define TEXTURE_C
# include "structure.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_texture(t_struct *glob, char **map, _Bool stop);
void	ft_struct_charger(t_colors *colors);
int		*ft_blocks(char *str);
int		*ft_colors(t_map *info, t_opps *bad, char c);
void	ft_update_anim(t_struct* glob);

#endif	