/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:31:59 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 11:21:15 by tmouche          ###   ########.fr       */
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
	glob.info = &info;
	glob.info->c_map = _read_map(av[1]);
	if (!glob.info->c_map)
		return (-1);
	if (_map_checker(glob.info, glob.info->c_map) == -1)
		return (_freemap(glob.info->c_map), -1);
	_fixer_map(&glob);
	_window(&glob);
	_free_all(&glob, 5);
	return (0);
}
