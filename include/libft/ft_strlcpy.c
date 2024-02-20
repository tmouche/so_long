/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:38:07 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/19 16:58:46 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size <= 0)
		return (ft_strlen(src, 0));
	i = -1;
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	dst[i] = 0;
	return (ft_strlen(src, 0));
}
