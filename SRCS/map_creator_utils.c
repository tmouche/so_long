/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:47 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 11:55:17 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "../HDRS/structure.h"
#include <unistd.h>

int	_strlen_cust(char *str, char sep)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != sep)
		i++;
	if (str[i] == sep)
		i++;
	return (i);
}

char	*_strjoin_map(char *s1, char *s2)
{
	char	*dest;
	int		index;
	int		index2;

	dest = ft_calloc(1, _strlen_cust(s1, 0) + _strlen_cust(s2, 0) + 1);
	if (!dest)
		return (free(s1), NULL);
	index = 0;
	if (s1)
	{
		while (s1[index])
		{
			dest[index] = s1[index];
			index++;
		}
		free (s1);
	}
	index2 = 0;
	while (s2[index2])
		dest[index++] = s2[index2++];
	return (dest);
}
