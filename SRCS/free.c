/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:54:22 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/03 17:15:46 by tmouche          ###   ########.fr       */
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
