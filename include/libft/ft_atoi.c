/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:23:50 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/27 11:13:55 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_atol(const char *nptr)
{
	size_t	i;
	size_t	result;
	int		sign;

	i = -1;
	sign = 1;
	result = 0;
	while ((nptr[++i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		;
	if (nptr[i] == 45 || nptr[i] == 43)
		if (nptr[i++] == 45)
			sign *= -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
		result = result * 10 + (nptr[i++] - 48);
	return (result * sign);
}

int	ft_atoi(const char *nptr)
{
	return ((int)(ft_atol(nptr)));
}
