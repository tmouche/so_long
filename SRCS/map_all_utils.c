/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_all_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 05:08:26 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 16:43:22 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"
#include "../include/libft/libft.h"
#include "../HDRS/structure.h"
#include "../HDRS/map.h"
#include <stdlib.h>
#include <time.h>

void	_check_char(char **map, char c)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
	{
		_freemap(map);
		ft_printf("Error : Forbidden character\n");
		exit (EXIT_FAILURE);
	}
		
}

int	_random(int seed, int proba)
{
	static int	mult = 1;
	int			randomnum;

	srand(time(NULL) * mult + seed);
	randomnum = rand() % proba;
	mult++;
	return (randomnum % proba);
}

void	_write_err(int err)
{
	int	write_err;

	write_err = ft_printf("Error : ");
	if (write_err > 0 && err == 1)
		ft_printf("Map non closed\n");
	else if (write_err > 0 && err == 2)
		ft_printf("Non resolvable map\n");
	else if (write_err > 0 && err == 3)
		ft_printf("Wrong map shape\n");
	else if (write_err > 0 && err == 404)
		ft_printf("Map not found\n");
}

char	**_copy_map(char **src)
{
	char	**dst;
	int		x1;
	int		x2;

	x1 = 0;
	while (src[x1])
		++x1;
	dst = malloc(sizeof(char *) * (x1 + 1));
	if (!dst)
		return (NULL);
	dst[x1] = 0;
	x1 = -1;
	while (src[++x1])
	{
		dst[x1] = malloc(ft_strlen(src[x1], 0) + 1);
		if (!dst[x1])
			return (_freemap(dst), NULL);
		x2 = -1;
		while (src[x1][++x2])
			dst[x1][x2] = src[x1][x2];
		dst[x1][x2] = 0;
	}
	return (dst);
}
