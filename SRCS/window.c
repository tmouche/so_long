/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:54:24 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/26 13:42:55 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "../HDRS/window.h"
#include "../HDRS/texture.h"
#include <stdio.h>

static void	_set_vars_img(t_struct *g, int x, int y)
{
	static t_vars	vars;
	static t_data	img;

	g->vars = &vars;
	g->img = &img;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		_free_all(g, 1);
	vars.win = mlx_new_window(vars.mlx, x, y, "So_long");
	if (!vars.win)
		_free_all(g, 2);
	img.img = mlx_new_image(vars.mlx, x, y);
	if (!img.img)
		_free_all(g, 3);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
}

void	_window(t_struct *g)
{
	_set_vars_img(g, _pix_x(g->info->map_width), _pix_y(g->info->map_height));
	_load_textures(g);
	_texture_to_img(g, g->info, g->info->s_map);
	mlx_put_image_to_window(g->vars->mlx, g->vars->win, g->img->img, 0, 0);
	/*mlx_key_hook(vars.win, hook_release, glob);
	mlx_hook(vars.win, 2, 1L << 0, hook_press, glob);
	mlx_loop_hook(vars.mlx, ft_update, glob);
	mlx_loop(vars.mlx);*/
}
