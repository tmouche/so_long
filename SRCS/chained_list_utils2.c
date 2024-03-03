/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:01:26 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/03 17:13:44 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include <stdlib.h>

void	_lst_del_struct(t_opps *lst)
{
	t_opps	*temp_next;
	t_opps	*temp_prev;

	temp_next = lst->next;
	temp_prev = lst->prev;
	free (lst);
	if (temp_next)
		temp_next->prev = temp_prev;
	if (temp_prev)
		temp_prev->next = temp_next;
}

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
