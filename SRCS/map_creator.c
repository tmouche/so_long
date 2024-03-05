/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:41:04 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/05 19:17:05 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "../HDRS/map.h"
#include <unistd.h>
#include <fcntl.h>

static int		_lenght_map(char *path)
{
	int		fd;
	char	*c;
	int		size;
	int		temp;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	temp = 1;
	size = -1;
	while (temp > 0)
	{
		temp = read(fd, c, 1);
		if (temp < 0)
			return (0);
		++size;
	}
	close (fd);
	return (size);
}

char	**_read_map(char *path)
{
	char	*buff;
	char	**map;
	int		size;

	size = _lenght_map(path);
	buff = malloc(_lenght_map(path) + 1);
	if (buff)
}