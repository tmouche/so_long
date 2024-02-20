/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:31:59 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 13:44:32 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_map.h"
#include "../ft_error.h"
#include "../ft_window.h"
#include "../ft_movement.h"
#include "../mlx_linux/mlx.h"
#include "../ft_structure.h"
#include <fcntl.h>
#include <stdio.h>


int	main(int ac, char **av)
{
	int	fd;
	t_struct	glob;
	t_map	 	info;
	t_opps		*bad;
	(void)ac;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	glob.info = &info;
	glob.info->map = read_map(fd);
	if (ft_map_checker(glob.info, glob.info->map) == -1)
		return(ft_freemap(glob.info->map), -1);
	/*ft_set_map(glob.info);
	glob.info->map = ft_map_dup(&info);
	ft_window(&glob);
	ft_freemap(glob.info->map);
	return (0);*/
}

//https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html	