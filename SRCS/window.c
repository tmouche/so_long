/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:54:24 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 14:10:40 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_linux/mlx.h"
#include "../HDRS/window.h"
#include "../HDRS/texture.h"

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
	g->info->colors = _load_textures(g);
	ft_texture(glob, glob->info->map, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, hook_release, glob);
	mlx_hook(vars.win, 2, 1L << 0, hook_press, glob);
	mlx_loop_hook(vars.mlx, ft_update, glob);
	mlx_loop(vars.mlx);
}


/*void _window(t_struct *glob)
{
	t_vars 		vars;
	t_data 		img;
	t_colors	colors;
	int x;
	int y;

	x = ft_pix_x(glob->info->map_width);
	y = ft_pix_y(glob->info->map_height);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x, y, "So_long");
	img.img = mlx_new_image(vars.mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	ft_struct_charger(&colors);
	glob->info->colors = &colors;
	glob->img = &img;
	glob->vars = &vars;
	ft_texture(glob, glob->info->map, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, hook_release, glob);
	mlx_hook(vars.win, 2, 1L << 0, hook_press, glob);
	mlx_loop_hook(vars.mlx, ft_update, glob);
	mlx_loop(vars.mlx);
}*/
