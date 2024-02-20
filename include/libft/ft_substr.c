/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:16:25 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/19 16:59:05 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	size;
	size_t	i;

	size = ft_strlen(s, 0);
	if (start < size)
		size -= start;
	else
		size = 0;
	if (size >= len)
		size = len;
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < len && s[i] && start < ft_strlen(s, 0))
		dest[i] = s[start + i];
	dest[i] = 0;
	return (dest);
}
