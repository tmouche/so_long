/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 05:08:26 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 14:32:29 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"

void	_write_err(int err)
{
	int	write_err;

	write_err = ft_printf("error\n");
	if (write_err > 0 && err == 1)
		ft_printf("map non closed\n");
	else if (write_err > 0 && err == 2)
		ft_printf("Non resolvable map\n");
	else if (write_err > 0 && err == 3)
		ft_printf("wrong map shape\n");
	else if (write_err > 0 && err == 404)
		ft_printf("map not found\n");
}

void	_reset_map(char **map)
{
	int	x1;
	int	x2;

	x1 = 0;
	while (map[x1])
	{
		x2 = 0;
		while (map[x1][x2])
		{
			if (map[x1][x2] == '2')
				map[x1][x2] = '0';
			x2++;
		}
		x1++;
	}
}
