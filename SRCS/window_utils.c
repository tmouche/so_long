/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:01:52 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/23 18:49:53 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include <stdio.h>

int	_pix_x(size_t x)
{
	if (x * SPR_S > SSIZE_X)
		return (SSIZE_X);
	else
		return (x * SPR_S);
}

int	_pix_y(size_t y)
{
	if (y * SPR_S > SSIZE_Y)
		return (SSIZE_Y);
	else
		return (y * SPR_S);
}
