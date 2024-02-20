/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:25:11 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/15 19:46:16 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*res;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		temp = f(lst->content);
		newlist = ft_lstnew(temp);
		if (!newlist)
		{
			del(temp);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, newlist);
		lst = lst->next;
	}
	return (res);
}
