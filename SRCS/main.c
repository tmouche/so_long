/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:31:59 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/12 13:38:57 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf/ft_printf.h"
#include "../HDRS/structure.h"
#include "../HDRS/window.h"
#include "../HDRS/map.h"
#include <fcntl.h>

static int	_check_arg(char *arg)
{
	int	i;

	if (!arg)
		return (-1);
	i = 0;
	while (arg[i])
		++i;
	if (i < 5)
		return (-1);
	if (arg[i - 1] != 'r' || arg[i - 2] != 'e' || arg[i - 3] != 'b'
		|| arg[i - 4] != '.')
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_struct	glob;
	t_map		info;

	if (ac != 2 || _check_arg(av[1]) == -1)
		return (ft_printf("error : args issue\n"), 1);
	glob.info = &info;
	glob.info->c_map = _read_map(av[1]);
	if (!glob.info->c_map)
		return (ft_printf("error : args issue\n"), -1);
	if (_map_checker(glob.info, glob.info->c_map) == -1)
		return (_freemap(glob.info->c_map), -1);
	_fixer_map(&glob);
	_window(&glob);
	_free_all(&glob, 5);
	return (0);
}
