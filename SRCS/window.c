/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:54:24 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/01 16:34:58 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "../HDRS/structure.h"
#include "../HDRS/movement.h"
#include "../HDRS/texture.h"
#include "../HDRS/window.h"

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
	mlx_hook(g->vars->win, 3, 1L << 1, _key_release, g);
	mlx_hook(g->vars->win, 2, 1L << 0, _key_press, g);
	mlx_loop_hook(g->vars->mlx, _exchanger, g);
	mlx_loop(g->vars->mlx);
}
