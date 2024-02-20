/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:12:07 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 14:16:36 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "../HDRS/map.h"
#include "../HDRS/base.h"
#include <unistd.h>

static int	_dim_map(char *buff)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (buff[index])
	{
		if (buff[index] == '\n')
			count++;
		index++;
	}
	return (count);
}

static void	_erase_buff(char	*buff)
{
	int	index;
	int	offset;

	if (buff[0] == 0)
		return ;
	index = 0;
	while (buff[index] && buff[index] != '\n')
		index++;
	if (buff[index] == '\n')
		index++;
	offset = 0;
	while (buff[index])
	{
		buff[offset] = buff[index];
		offset++;
		index++;
	}
	while (buff[offset])
		buff[offset++] = 0;
}

static char	**_create_map(char **map, char *buff)
{
	int	count;

	map = ft_calloc(sizeof(char *), _dim_map(buff) + 1);
	if (!map)
		return (NULL);
	count = 0;
	while (buff[0])
	{
		map[count] = ft_calloc(sizeof(char), _strlen_cust(buff, '\n'));
		if (!map[count])
			return (_freemap(map), NULL);
		ft_strlcpy(map[count], buff, _strlen_cust(buff, '\n'));
		_erase_buff(buff);
		count++;
	}
	return (map);
}

static char	*_set_buff(int fd, char *buff)
{
	char	*temp;
	int		size;
	int		lap;

	temp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	size = read(fd, temp, BUFFER_SIZE);
	if (size < 0)
		return (NULL);
	temp[size] = 0;
	lap = 0;
	while (!(size < BUFFER_SIZE) || lap <= 1)
	{
		buff = _strjoin_map(buff, temp);
		if (!buff)
			return (free(temp), NULL);
		size = read(fd, temp, BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		temp[size] = 0;
		if (size < BUFFER_SIZE)
			lap++;
	}
	return (free(temp), buff);
}

char	**_read_map(int fd)
{
	char	*buff;
	char	**map;
	int		size;

	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	size = read(fd, buff, BUFFER_SIZE);
	if (size < 0)
		return (free (buff), NULL);
	buff[size] = 0;
	if (size == BUFFER_SIZE)
	{
		buff = _set_buff(fd, buff);
		if (!buff)
			return (free(buff), NULL);
	}
	map = NULL;
	map = _create_map(map, buff);
	if (!map)
		return (free(buff), NULL);
	return (free(buff), map);
}
