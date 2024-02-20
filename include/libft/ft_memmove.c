/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:42:54 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/09 11:06:58 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (&((char *)dest)[0] > &((const char *)src)[0]
		&& &((const char *)src)[0] + n > &((char *)dest)[0])
	{
		i = n;
		while (i--)
			((char *)dest)[i] = ((const char *)src)[i];
	}
	else
		return (ft_memcpy(dest, src, n));
	return (dest);
}
