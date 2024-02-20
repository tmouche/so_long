/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:16:29 by tmouche           #+#    #+#             */
/*   Updated: 2024/01/29 18:48:04 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_structure.h"
#include "../ft_movement.h"

void	ft_reset_chara(char **map, int x1, int x2)
{
	int	offset_x1;
	int	offset_x2;
	
	offset_x1 = 0;
	while (offset_x1 < 3)
	{
		offset_x2 = 0;
		while (offset_x2 < 3)
		{
			map[x1 + offset_x1][x2 + offset_x2] = '0';
			offset_x2++;
		}
		offset_x1++;
	}
}

void	ft_replace_chara(char **map, int x1, int x2, char c)
{
	int	offset_x1;
	int	offset_x2;
	
	offset_x1 = 0;
	while (offset_x1 < 3)
	{
		offset_x2 = 0;
		while (offset_x2 < 3)
		{
			map[x1 + offset_x1][x2 + offset_x2] = c;
			offset_x2++;
		}
		offset_x1++;
	}
}

int	(*ft_chk_v(int x1, int x2, int o_x1))[2]
{
	static int	check[3][2];
	
	if (o_x1 == -1)
	{	
		check[0][0] = x1 + o_x1;
		check[0][1] = x2;
		check[1][0] = x1 + o_x1;
		check[1][1] = x2 + 1;
		check[2][0] = x1 + o_x1;
		check[2][1] = x2 + 2;
	}
	else
	{
		check[0][0] = x1 + 2 + o_x1;
		check[0][1] = x2;
		check[1][0] = x1 + 2 + o_x1;
		check[1][1] = x2 + 1;
		check[2][0] = x1 + 2 + o_x1;
		check[2][1] = x2 + 2;
	}
	return (check);
}

int	(*ft_chk_h(int x1, int x2, int o_x2))[2]
{
	static int	check[3][2];
	
	if (o_x2 == -1)
	{
		check[0][0] = x1;
		check[0][1] = x2 + o_x2;
		check[1][0] = x1 + 1;
		check[1][1] = x2 + o_x2;
		check[2][0] = x1 + 2;
		check[2][1] = x2 + o_x2;
	}
	else
	{
		check[0][0] = x1;
		check[0][1] = x2 + 2 + o_x2;
		check[1][0] = x1 + 1;
		check[1][1] = x2 + 2 + o_x2;
		check[2][0] = x1 + 2;
		check[2][1] = x2 + 2 + o_x2;
	}
	return (check);
}

int	(*ft_chk_d(int x1, int x2, int m_x1, int m_x2))[2]
{
	static int	check[1][2];

	if (m_x1 == 1)
		check[0][0] = x1 + 3;
	else
		check[0][0] = x1 - 1;
	if (m_x2 == 1)
		check[0][1] = x2 + 3;
	else
		check[0][1] = x2 - 1;
	return (check);
}
