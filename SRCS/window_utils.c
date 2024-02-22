/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:01:52 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 13:34:52 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include <stdio.h>

int	_pix_x(size_t x)
{
	if (x * SPRITE_SIZE > SCREEN_X)
		return (SCREEN_X);
	else
		return (x * SPRITE_SIZE);
}

int	_pix_y(size_t y)
{
	if (y * SPRITE_SIZE > SCREEN_Y)
		return (SCREEN_Y);
	else
		return (y * SPRITE_SIZE);
}
