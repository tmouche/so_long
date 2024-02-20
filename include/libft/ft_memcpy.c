/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:17:46 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/10 15:31:02 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == 0 && src == 0)
		return (0);
	if (&((char *)dest)[0] > &((const char *)src)[0]
		&& &((const char *)src)[0] + n > &((char *)dest)[0])
		return (ft_memmove(dest, src, n));
	i = -1;
	while (++i < n)
		((char *)dest)[i] = ((const char *)src)[i];
	return (dest);
}
