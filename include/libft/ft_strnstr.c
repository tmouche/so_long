/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:53 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/10 10:06:24 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	add;

	index = -1;
	if (*little == 0)
		return ((char *)big);
	while (big[++index] && index < len)
	{
		add = 0;
		while (big[index + add] == little[add] && index + add < len
			&& little[add])
			add++;
		if (little[add] == 0)
			return (&((char *)big)[index]);
	}
	return (0);
}
