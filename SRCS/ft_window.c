/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:54:24 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 11:28:39 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_window.h"
#include "../ft_movement.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include "../ft_map.h"
#include "../ft_base.h"
#include "../ft_texture.h"
#include <time.h>
#include <stddef.h>
#include <stdio.h>

int	ft_pix_x(size_t x)
{
	if (x * SPRITE_SIZE > SCREEN_X)
		return (SCREEN_X);
	else
		return (x * SPRITE_SIZE);
}

int	ft_pix_y(size_t y)
{
	if (y * SPRITE_SIZE > SCREEN_Y)
		return (SCREEN_Y);
	else
		return (y * SPRITE_SIZE);
}

void ft_new_frame(t_struct *glob)	
{
	char *str;

	str = ft_give_step(glob->info->collect, glob->info->step);
	if (!str)
		return;
	ft_texture(glob, glob->info->map, 0);
	mlx_clear_window(glob->vars->mlx, glob->vars->win);
	mlx_put_image_to_window(glob->vars->mlx, glob->vars->win, glob->img->img, 0, 0);
	mlx_string_put(glob->vars->mlx, glob->vars->win, 10, 10, 16777215, str);
	free(str);
}

int	hook_release(int keycode, t_struct *glob)
{
	if (keycode == 'w')
		glob->info->mv_y = 0;
	if (keycode == 'a')
		glob->info->mv_x = 0;
	if (keycode == 's')
		glob->info->mv_y = 0;
	if (keycode == 'd')
		glob->info->mv_x = 0;
	if (keycode >= 65361 && keycode <= 65364 && glob->info->proj->limit == 0)
		ft_set_proj(glob->info, keycode);
	return (0);
}

int hook_press(int keycode, t_struct *glob)
{
	if (keycode == 'w')
		glob->info->mv_y = -1;
	if (keycode == 'a')
		glob->info->mv_x = -1;
	if (keycode == 's')
		glob->info->mv_y = 1;
	if (keycode == 'd')
		glob->info->mv_x = 1;
	return (0);
}

int ft_update(t_struct *glob)
{
	static unsigned int	lap = 0;
	static unsigned int lap_fps = 0;
	static unsigned int lap_proj = 0;

	lap++;
	lap_proj++;
	lap_fps++;
	if (POWER / 10 / lap_proj == 1)
	{
		if (glob->info->proj->limit > 0)
			ft_projectile(glob->info, glob->info->proj, glob->info->map);
		ft_update_anim(glob);
		lap_proj = 0;
	}
	if (POWER / 3 / lap == 1)
	{
		if (glob->info->proj->limit == 0)
			ft_player(glob->info, glob->info->mv_y, glob->info->mv_x);
		ft_ennemies(glob->info, glob->info->bad);
		lap = 0;
	}
	if (POWER / 60 / lap_fps == 1)
	{
		ft_new_frame(glob);
		lap_fps = 0;
	}
	return (0);
}

void ft_window(t_struct *glob)
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
}
