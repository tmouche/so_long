/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:04:51 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/19 16:58:37 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	lengthdst;

	lengthdst = ft_strlen(dst, 0);
	index = -1;
	if (size <= lengthdst)
		return (ft_strlen(src, 0) + size);
	while (src[++index] && (lengthdst + index) < (size - 1))
		dst[lengthdst + index] = src[index];
	dst[lengthdst + index] = 0;
	return (lengthdst + ft_strlen(src, 0));
}
