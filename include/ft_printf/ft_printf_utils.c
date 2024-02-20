/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:11:39 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/16 14:24:49 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

ssize_t	_putstr(char *str)
{
	size_t	len;

	len = _strlen(str);
	if (!str)
		return (write(1, "(null)", 6));
	if (write(1, &str[0], len) == -1)
		return (-1);
	return (len);
}

ssize_t	ft_putstr_stoped(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '%')
		len++;
	if (write(1, &str[0], len) == -1)
		return (-1);
	return (len);
}

int	ft_counter(int *total, int len)
{
	if (len == -1)
		*total = -1;
	else
		*total += len;
	return (*total);
}
