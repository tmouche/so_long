/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:43:12 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 15:51:57 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include <unistd.h>
#include <fcntl.h>

void _mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	_load_anim_textures(t_struct *g, t_colors *colors)
{
	colors->player_shoot1_left = _txt_sprite(g, "graph/player_shoot1_left.txt");
	colors->player_shoot2_left = _txt_sprite(g, "graph/player_shoot2_left.txt");
	colors->player_shoot3_left = _txt_sprite(g, "graph/player_shoot3_left.txt");
	colors->player_shoot4_left = _txt_sprite(g, "graph/player_shoot4_left.txt");
	colors->player_shoot5_left = _txt_sprite(g, "graph/player_shoot5_left.txt");
	colors->player_shoot1_right = _txt_sprite(g, "graph/player_shoot1_right.txt");
	colors->player_shoot2_right = _txt_sprite(g, "graph/player_shoot2_right.txt");
	colors->player_shoot3_right = _txt_sprite(g, "graph/player_shoot3_right.txt");
	colors->player_shoot4_right = _txt_sprite(g, "graph/player_shoot4_right.txt");
	colors->player_shoot5_right = _txt_sprite(g, "graph/player_shoot5_right.txt");
	colors->explosion_1 = _txt_sprite(g, "graph/explosion_1.txt");
	colors->explosion_2 = _txt_sprite(g, "graph/explosion_2.txt");
	colors->explosion_3 = _txt_sprite(g, "graph/explosion_3.txt");
	colors->explosion_4 = _txt_sprite(g, "graph/explosion_4.txt");
	colors->explosion_5 = _txt_sprite(g, "graph/explosion_5.txt");
	colors->explosion_6 = _txt_sprite(g, "graph/explosion_6.txt");
}

t_colors	*_load_textures(t_struct *g)
{
	static t_colors	colors;
	
	colors.player_left = _txt_sprite(g, "graph/player_left.txt");
	colors.player_right = _txt_sprite(g, "graph/player_right.txt");
	colors.opps_bot = _txt_sprite(g, "graph/opps_bot.txt");
	colors.opps_mid = _txt_sprite(g, "graph/opps_mid.txt");
	colors.opps_top = _txt_sprite(g, "graph/opps_top.txt");
	colors.collect = _txt_sprite(g, "graph/collec.txt");
	colors.door = _txt_sprite(g, "graph/door.txt");
	colors.empty = _txt_sprite(g, "graph/empty.txt");
	colors.wall = _txt_sprite(g, "graph/wall.txt");
	colors.proj = _txt_sprite(g, "graph/proj.txt");
	ft_struct_charger_anim(colors);
	return (&colors);
}

static int	_set_hexa_color(char *src, int *i)
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

int	*_txt_sprite(t_struct *g, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		*colors;
	int		fd;
	int		i[1];
	int		index;
	
	fd = open(str, O_RDONLY);
	*i = read(fd, buff, BUFFER_SIZE);
	close(fd);
	if (*i < 0)
		_free_all(g, 5);
	colors = malloc(sizeof(int) * (SPR_S * SPR_S));
	if (!colors)
		_free_all(g, 5);
	buff[*i] = 0;
	*i = 0;
	index = 0;
	while (index < (SPR_S * SPR_S))
	{
		colors[index] = _set_hexa_color(buff, i);
		index++;
	}
	return (colors);
}
