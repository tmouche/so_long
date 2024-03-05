/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:54:22 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/05 15:20:08 by tmouche          ###   ########.fr       */
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
	{
		free(map[i]);
		++i;
	}
	free(map);
}

static void	_free_s_map(t_map *info, t_block ***s_map)
{
	t_opps	*bad;
	t_opps	*temp;
	int		x1;

	bad = *info->bad;
	while (bad)
	{
		temp = bad->next;
		if (bad->x1 > 0)
			free (s_map[bad->x1][bad->x2]);
		free (bad);
		bad = temp;
	}
	x1 = -1;
	while (s_map[++x1])
		free (s_map[x1]);
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
		_free_s_map(g->info, g->info->s_map);
	if (stop > 1)
		_free_mlx(g->vars, g->img, stop);
	if (stop > 4)
		_free_texture_a(g->info->colors);
	exit (EXIT_FAILURE);
}
