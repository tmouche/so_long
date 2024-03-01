/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:31:59 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/01 14:09:22 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/window.h"
#include "../HDRS/map.h"
#include <fcntl.h>
#include <stdio.h>

/*void	_printer(t_block ***s_map)
{
	int	x1;
	int	x2;

	x1 = 0;
	while (s_map[x1])
	{	
		x2 = 0;
		while(s_map[x1][x2])
		{
			printf("cc : {%d; %d}\n", x1, x2);
			printf("type = %c\n", s_map[x1][x2]->type);
			if (s_map[x1][x2]->type == 'D')
			{
				printf("bad = %p\n", s_map[x1][x2]->bad);
				printf("cc bad : {%d; %d}\n", s_map[x1][x2]->bad->x1, s_map[x1][x2]->bad->x2);
				printf("state : %d\n", s_map[x1][x2]->bad->state);
			}
			++x2;
		}
		++x1;
	}
}*/

int	main(int ac, char **av)
{
	t_struct	glob;
	t_map		info;
	int			fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	glob.info = &info;
	glob.info->c_map = _read_map(fd);
	if (_map_checker(glob.info, glob.info->c_map) == -1)
		return (_freemap(glob.info->c_map), -1);	
	_fixer_map(&glob);
	//_printer(info.s_map);
	_window(&glob);
	_free_all(&glob, 5);
	return (0);
}
