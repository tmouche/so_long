/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:31:59 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 16:43:47 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/map.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_struct	glob;
	t_map		info;
	t_opps		*bad;
	int			fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	glob.info = &info;
	glob.info->map = _read_map(fd);
	if (_map_checker(glob.info, glob.info->map) == -1)
		return (_freemap(glob.info->map), -1);
	bad = NULL;
	_fixer_map(glob.info, &bad);
	/*glob.info->map = ft_map_dup(&info);
	ft_window(&glob);
	ft_freemap(glob.info->map);*/
	_freemap(glob.info->map);
	return (0);
}
