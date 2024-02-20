/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:27:24 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/19 16:57:28 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	index;
	size_t	index2;

	dest = malloc(ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1);
	if (!dest)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		dest[index] = s1[index];
		index++;
	}
	index2 = 0;
	while (s2[index2])
	{
		dest[index] = s2[index2];
		index2++;
		index++;
	}
	dest[index] = 0;
	return (dest);
}
