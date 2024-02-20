/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:12:08 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/16 14:24:24 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void	ft_putnbr_base(ssize_t nbr, char *base, int *len)
{
	ssize_t	base_len;

	base_len = _strlen(base);
	if (*len == -1)
		return ;
	if (nbr < 0)
	{
		ft_counter(len, write(1, "-", 1));
		nbr *= -1;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base, len);
		ft_counter(len, write(1, &base[nbr % base_len], 1));
		if (*len == -1)
			return ;
	}
	if (nbr < base_len)
		ft_counter(len, write(1, &base[nbr % base_len], 1));
	return ;
}

static void	ft_putnbr_bu(size_t nbr, char *base, int *len)
{
	size_t	base_len;

	base_len = _strlen(base);
	if (*len == -1)
		return ;
	if (nbr >= base_len)
	{
		ft_putnbr_bu(nbr / base_len, base, len);
		ft_counter(len, write(1, &base[nbr % base_len], 1));
		if (*len == -1)
			return ;
	}
	if (nbr < base_len)
		ft_counter(len, write(1, &base[nbr % base_len], 1));
	return ;
}

static void	ft_print_memory(size_t nbr, int *len)
{
	if ((char *)nbr == NULL)
	{
		*len = _putstr("(nil)");
		return ;
	}
	*len = _putstr("0x");
	if (*len == -1)
		return ;
	ft_putnbr_bu(nbr, "0123456789abcdef", len);
}

static int	ft_find_conversion(char c, va_list para)
{
	int	len[1];

	*len = 0;
	if (c == 'c')
		*len = _putchar(va_arg(para, int));
	else if (c == 's')
		*len = _putstr(va_arg(para, char *));
	else if (c == 'p')
		ft_print_memory(va_arg(para, size_t), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(para, int), "0123456789", len);
	else if (c == 'u')
		ft_putnbr_bu(va_arg(para, unsigned int), "0123456789", len);
	else if (c == 'x')
		ft_putnbr_bu(va_arg(para, unsigned int), "0123456789abcdef", len);
	else if (c == 'X')
		ft_putnbr_bu(va_arg(para, unsigned int), "0123456789ABCDEF", len);
	else if (c == '%')
		ft_counter(len, write(1, "%", 1));
	return (*len);
}

int	ft_printf(const char *prompt, ...)
{
	va_list	para;
	int		i;
	int		total[1];

	i = 0;
	*total = 0;
	va_start(para, prompt);
	if (!prompt)
		return (-1);
	while (prompt[i])
	{
		ft_counter(total, ft_putstr_stoped((char *)&prompt[i]));
		while (prompt[i] != '%' && prompt[i])
			i++;
		if (*total == -1)
			return (va_end(para), -1);
		if (prompt[i] == 0)
			break ;
		i++;
		ft_counter(total, ft_find_conversion(prompt[i], para));
		if (*total == -1)
			return (va_end(para), -1);
		i++;
	}
	return (va_end(para), *total);
}
