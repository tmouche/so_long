/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ennemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:50:42 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 13:05:55 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_structure.h"
#include "../ft_map.h"

void	_kill_opps(t_opps *bad, int x1, int x2)
{
	int	temp_x1;
	int temp_x2;

	while (bad)
	{
		temp_x1 = x1;
		while (bad->x1 != temp_x1 && x1 - temp_x1 < 2)
			temp_x1--;
		temp_x2 = x2;
		while (bad->x2 != temp_x2 && x2 - temp_x2 < 2)
			temp_x2--;
		if (bad->x1 == temp_x1 && bad->x2 == temp_x2)
		{
			bad->state = -1;
			return ;
		}
		bad = bad->next;
	}
}

int	ft_pos_opps(t_opps **bad, int x1, int x2)
{
	t_opps	*temp;

	temp = _lstnew(x1, x2);
	if (!temp)
		return (_lstclear(bad), -1);
	if (ft_random(1, 2) == 0)
		temp->dir = 1;
	if (ft_random(1, 2) == 0)
		temp->sens = -1;
	if (x1 % 3 == 0)
		temp->state == 0;
	else if (x1 % 2 == 0)
		temp->state == 1;
	else
		temp->state == 2;
	_lstadd_back(bad, temp);
	return (0);
}
