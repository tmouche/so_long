/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:41:04 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/11 18:16:39 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "../HDRS/map.h"
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

static int	_lenght_map(char *path)
{
	int		fd;
	char	c[1];
	int		size;
	int		temp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	temp = 1;
	size = 0;
	while (temp > 0)
	{
		temp = read(fd, c, 1);
		if (temp < 0)
			return (0);
		++size;
		if (size == INT_MAX)
			return (0);
	}
	close (fd);
	return (size);
}

char	**_read_map(char *path)
{
	char	**map;
	char	*buff;
	int		size;
	int		fd;

	size = _lenght_map(path);
	if (size < 2)
		return (NULL);
	buff = malloc(size + 1);
	if (!buff)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (free (buff), NULL);
	size = read(fd, buff, size);
	if (size == -1)
		return (free (buff), NULL);
	buff[size] = 0;
	close (fd);
	map = ft_split(buff, '\n');
	return (free (buff), map);
}
