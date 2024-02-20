/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:43:12 by tmouche           #+#    #+#             */
/*   Updated: 2024/01/18 13:47:07 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_window.h"
#include "../libft/libft.h"
#include "../ft_base.h"
#include "../ft_map.h"
#include "../ft_texture.h"
#include <unistd.h>
#include <fcntl.h>

void ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_set_hex_color(char *src, int *i)
{
	int	result;
	int	sign;
	
	result = 0;
	sign = 1;
	while(src[*i] == '\n' || src[*i] == ' ')
		i[0]++;
	if (src[*i] == '-')
	{
		sign = -1;
		i[0]++;
	}
	while(src[*i] >= '0' && src[*i] <= '9')
	{
		result *= 10;
		result = result + (src[*i] - 48);
		i[0]++;
	}
	return (result * sign);
}

int	*ft_blocks(char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		*colors;
	int		fd;
	int		i[1];
	int		index;
	
	colors = malloc(sizeof(int) * (SPRITE_SIZE * SPRITE_SIZE));
	if (!colors)
		return (NULL);
	fd = open(str, O_RDONLY);
	*i = read(fd, buff, BUFFER_SIZE);
	if (*i < 0)
		return (NULL);
	buff[*i] = 0;
	*i = 0;
	index = 0;
	while (index < (SPRITE_SIZE * SPRITE_SIZE))
	{
		colors[index] = ft_set_hex_color(buff, i);
		index++;
	}
	return (colors);
}
