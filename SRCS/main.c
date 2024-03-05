/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:31:59 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/05 18:55:10 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"
#include "../HDRS/structure.h"
#include "../HDRS/window.h"
#include "../HDRS/map.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_struct	glob;
	t_map		info;

	if (ac != 2)
	{
		ft_printf("error : args issue\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	glob.info = &info;
	glob.info->c_map = _read_map(fd);
	if (_map_checker(glob.info, glob.info->c_map) == -1)
		return (_freemap(glob.info->c_map), -1);
	_fixer_map(&glob);
	_window(&glob);
	_free_all(&glob, 5);
	return (0);
}
