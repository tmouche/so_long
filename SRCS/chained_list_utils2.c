/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:01:26 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 11:17:34 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_structure.h"
#include <stdlib.h>

void	_lstclear(t_opps **lst)
{
	t_opps	*temp;

	if (!lst)
		return ;
	temp = *lst;
	while (*lst)
	{
		temp = temp->next;
		free(*lst);
		*lst = temp;
	}
}
