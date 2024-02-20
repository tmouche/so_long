/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:51:24 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/21 13:13:25 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;

	if (nmemb == 0 || size == 0)
	{
		alloc = malloc(size * nmemb);
		return (alloc);
	}
	if (size > (SIZE_MAX / nmemb) || nmemb > (SIZE_MAX / size))
		return (NULL);
	alloc = malloc(size * nmemb);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, size * nmemb);
	return (alloc);
}
