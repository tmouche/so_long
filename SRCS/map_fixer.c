/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fixer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:34:19 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/29 17:55:17 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/map.h"
#include <stdlib.h>

static t_opps	*_fixer_opps(t_opps **bad, int x1, int x2)
{
	static int	seed = 1;
	t_opps		*temp;

	temp = _lstnew(x1, x2);
	if (!temp)
		return (_lstclear(bad), NULL);
	if (_random(1, 2) == 0)
		temp->dir = 1;
	if (_random(1, 2) == 0)
		temp->sens = -1;
	if (x1 % seed == 0)
		temp->state = 0;
	else if (x1 % (seed + 1) == 0)
		temp->state = 1;
	else
		temp->state = 2;
	_lstadd_back(bad, temp);
	++seed;
	return (temp);
}

static void	_create_square(t_block ***s_map, t_block *block, int x1, int x2)
{
	int	temp_x1;
	int	temp_x2;

	temp_x1 = 0;
	while (temp_x1 < 3)
	{
		temp_x2 = 0;
		while (++temp_x2 < 3)
		{
			s_map[x1 + temp_x1][x2 + temp_x2] = block;
			++temp_x2;
		}
		++temp_x1;
	}
}

static void	_putchar_map(char c, t_struct *g, int x1, int x2)
{
	t_block	*block;

	if (c == '0')
		_create_square(g->info->s_map, NULL, x1, x2);
	else
	{
		block = malloc(sizeof(t_block));
		if (!block)
			_free_all(g, 1);
		block->nature = c;
		block->bad = NULL;
		if (c == 'D')
		{
			block->bad = _fixer_opps(g->info->bad, x1, x2);
			if (!block->bad)
				_free_all(g, 0);
		}
		_create_square(g->info->s_map, block, x1, x2);
	}
}

/*static void	_putchar_map(char c, t_struct *g, int x1, int x2)
{
	t_block	*block;
	int		temp_x1;
	int		temp_x2;

	block = malloc(sizeof(t_block));
	if (!block)
		_free_all(g, 1);
	block->nature = c;
	block->bad = NULL;
	if (c == 'D')
	{
		block->bad = _fixer_opps(g->info->bad, x1, x2);
		if (!block->bad)
			_free_all(g, 0);
	}
	temp_x1 = -1;
	while (++temp_x1 < 3)
	{
		temp_x2 = -1;
		while (++temp_x2 < 3)
			g->info->s_map[x1 + temp_x1][x2 + temp_x2] = block;
	}
}*/

static void	_fill_map(t_struct *g, char **c_map)
{
	int	x1_s;
	int	x2_s;
	int	x1_c;
	int	x2_c;

	x1_s = 0;
	x1_c = -1;
	while (c_map[++x1_c])
	{
		x2_s = 0;
		x2_c = -1;
		while (c_map[x1_c][++x2_c])
		{
			if (c_map[x1_c][x2_c] == '1' && x1_c != 0
					&& x1_c != g->info->map_height - 1
					&& x2_c != 0 && x2_c != g->info->map_width - 1)
				c_map[x1_c][x2_c] = '2';
			if (c_map[x1_c][x2_c] == '0')
				if (_random(x1_c + x2_c, g->info->map_width) == 0)
					c_map[x1_c][x2_c] = 'D';
			_putchar_map(c_map[x1_c][x2_c], g, x1_s, x2_s);
			x2_s += 3;
		}
		x1_s += 3;
	}
}

void	_fixer_map(t_struct *g)
{
	static t_block	***s_map;
	static t_opps	*bad;
	int				i;

	bad = NULL;
	s_map = malloc(sizeof(t_block **) * (g->info->map_height * 3 + 1));
	if (!s_map)
		return ;
	s_map[g->info->map_height * 3] = NULL;
	i = 0;
	while (i < g->info->map_height * 3)
	{
		s_map[i] = malloc(sizeof(t_block *) * (g->info->map_width * 3 + 1));
		if (!s_map[i])
			_free_all(g, 0);
		s_map[i][g->info->map_width * 3] = NULL;
		++i;
	}
	g->info->bad = &bad;
	g->info->s_map = s_map;
	_fill_map(g, g->info->c_map);
}
