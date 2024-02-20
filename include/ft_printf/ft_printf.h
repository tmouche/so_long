/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:13:41 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/16 14:23:59 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>

int		_putchar(char c);
ssize_t	_putstr(char *str);
int		ft_printf(const char *prompt, ...);
size_t	_strlen(const char *s);
ssize_t	ft_putstr_stoped(char *str);
int		ft_counter(int *total, int len);

#endif