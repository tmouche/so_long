/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:22 by tmouche           #+#    #+#             */
/*   Updated: 2024/01/26 16:43:50 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_structure.h"
#include "../ft_movement.h"

static void	ft_destruct_collect(t_map *info, int (*check)[2], int i)
{
	int	x1;
	int x2;

	x1 = check[i][0];
	x2 = check[i][1];
	while (x1 % 3 != 0)
		x1--;
	while (x2 % 3 != 0)
		x2--;
	info->collect--;
	ft_reset_chara(info->map, x1, x2);
}

/*int	ft_is_a_door(t_map *info, int (*k)[2], int i)
{
	int	res;

	if (i == 1)
		return (close);
	res = ft_check_char(info->map[k[1][0]][k[1][1]]); 
	if (res < 0)
		return (res);
	if (res == 2)
	{
		if (k[0][0] % 3 == k[1][0] % 3 || k[0][1] % 3 == k[1][1] % 3)
		{
			ft_destruct_collect(info, k, 0);
			ft_destruct_collect(info, k, 1);
			return (2);
		}
	}
	ft_destruct_collect(info, k, 0);
	return (2);		
}*/

int	ft_is_a_collect(t_map *info, int (*k)[2], int i)
{
	while (++i <= 2)
	{
		if (info->map[k[i][0]][k[i][1]] == 'C')
			ft_destruct_collect(info, k, i);
	}
	return (2);
}
