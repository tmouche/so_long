/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:25:44 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/15 20:10:34 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_absv(int n)
{
	if (n == -2147483648)
		return (-n - 1);
	if (n < 0)
		return (-n);
	else
		return (n);
}

static char	*ft_fillres(char *res, int n, int size)
{
	int	i;
	int	temp;

	if (n < 0)
		res[0] = 45;
	temp = ft_absv(n);
	i = size;
	res[i] = 0;
	i--;
	while (temp >= 10)
	{
		res[i] = temp % 10 + 48;
		temp /= 10;
		i--;
	}
	if (n == -2147483648)
		res[10] += 1;
	res[i] = temp + 48;
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		temp;

	size = 0;
	if (n <= 0)
		size++;
	temp = ft_absv(n);
	while (temp > 0)
	{
		temp /= 10;
		size++;
	}
	res = malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	return (ft_fillres(res, n, size));
}
