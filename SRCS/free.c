/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:54:22 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/01 18:25:40 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "../HDRS/structure.h"
#include <stdlib.h>

void	_freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void	_free_s_map(t_map *info, t_block ***s_map, int stop)
{
	int	temp;
	int	x1;
	int	x2;

	x1 = 0;
	while (s_map[x1])
	{
		x2 = 0;
		if (stop > 0)
		{
			while (s_map[x1][x2])
			{
				if (s_map[x1][x2]->type == 'D' && s_map[x1][x2]->bad)
					free (s_map[x1][x2]->bad);
				if (s_map[x1][x2]->type != '0')
					free (s_map[x1][x2]);
				x2 += 3;
			}
		}
		temp = -1;
		while (++temp < 3)
			free (s_map[x1 + temp]);
		x1 += 3;
	}
	free (info->empty);
	free (s_map);
}

static void	_free_mlx(t_vars *vars, t_data *img, int stop)
{
	if (stop >= 4)
		mlx_destroy_image(vars->mlx, img->img);
	if (stop >= 3)
		mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
}

static void	_free_texture_c(t_colors *colors)
{
	if (colors->explosion_3)
		free (colors->explosion_3);
	if (colors->explosion_4)
		free (colors->explosion_4);
	if (colors->explosion_5)
		free (colors->explosion_5);
	if (colors->explosion_6)
		free (colors->explosion_6);
}

static void	_free_texture_b(t_colors *colors)
{
	if (colors->p_shoot2_l)
		free (colors->p_shoot2_l);
	if (colors->p_shoot3_l)
		free (colors->p_shoot3_l);
	if (colors->p_shoot4_l)
		free (colors->p_shoot4_l);
	if (colors->p_shoot5_l)
		free (colors->p_shoot5_l);
	if (colors->p_shoot1_r)
		free (colors->p_shoot1_r);
	if (colors->p_shoot2_r)
		free (colors->p_shoot2_r);
	if (colors->p_shoot3_r)
		free (colors->p_shoot3_r);
	if (colors->p_shoot4_r)
		free (colors->p_shoot4_r);
	if (colors->p_shoot5_r)
		free (colors->p_shoot5_r);
	if (colors->explosion_1)
		free (colors->explosion_1);
	if (colors->explosion_2)
		free (colors->explosion_2);
	_free_texture_c(colors);
}

static void	_free_texture_a(t_colors *colors)
{
	if (colors->p_l)
		free (colors->p_l);
	if (colors->p_r)
		free (colors->p_r);
	if (colors->opps_bot)
		free (colors->opps_bot);
	if (colors->opps_mid)
		free (colors->opps_mid);
	if (colors->opps_top)
		free (colors->opps_top);
	if (colors->collect)
		free (colors->collect);
	if (colors->door)
		free (colors->door);
	if (colors->empty)
		free (colors->empty);
	if (colors->wall)
		free (colors->wall);
	if (colors->laser_1)
		free (colors->laser_1);
	if (colors->p_shoot1_l)
		free (colors->p_shoot1_l);
	_free_texture_b(colors);
}

void	_free_all(t_struct *g, int stop)
{
	_freemap(g->info->c_map);
	if (stop >= 0)
		_free_s_map(g->info, g->info->s_map, stop);
	if (stop > 1)
		_free_mlx(g->vars, g->img, stop);
	if (stop > 4)
		_free_texture_a(g->info->colors);
	exit (EXIT_FAILURE);
}
