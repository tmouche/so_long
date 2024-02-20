/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:33:19 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 16:47:22 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include <stdlib.h>

t_opps	*_lstnew(int x1, int x2)
{
	t_opps	*new;

	new = malloc(sizeof(t_opps));
	if (!new)
		return (NULL);
	new->x1 = x1;
	new->x2 = x2;
	new->dir = 0;
	new->sens = 1;
	new->state = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	_lstsize(t_opps *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_opps	*_lstlast(t_opps *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	_lstadd_back(t_opps **lst, t_opps *new)
{
	t_opps	*lst_temp;

	if (*lst)
	{
		lst_temp = _lstlast(*lst);
		lst_temp->next = new;
		new->prev = lst_temp;
		new->next = NULL;
	}
	else
		*lst = new;
	return (0);
}

void	_lstadd_front(t_opps **lst, t_opps *new)
{
	if (*lst)
		(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
	new->prev = NULL;
}
