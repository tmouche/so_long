/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:31:29 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/15 12:58:48 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checker_set(char const *set, char c)
{
	size_t	i;

	i = -1;
	if (*set != 0)
		while (set[++i])
			if (set[i] == c)
				return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	index;
	size_t	indexstart;
	char	*dest;

	index = -1;
	while (ft_checker_set(set, s1[++index]) == 1)
		;
	indexstart = index;
	while (s1[index])
		index++;
	if (s1[indexstart] != 0)
		while (ft_checker_set(set, s1[index - 1]) == 1)
			index--;
	dest = ft_calloc(sizeof(char), index - indexstart + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (indexstart < index && index != 0)
	{
		dest[i] = s1[indexstart++];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
