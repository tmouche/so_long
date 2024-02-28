/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:01:52 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/28 15:24:47 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "../include/libft/libft.h"
#include "../HDRS/structure.h"
#include <stdlib.h>

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

int	_disp_info(t_struct *g, int collec, int step)
{
	char	*collec_str ;
	char	*step_str;
	char	*result;
	char	*temp;

	temp = ft_itoa(step / 3);
	step_str = ft_strjoin("STEP : ", temp);
	free (temp);
	temp = ft_itoa(collec);
	collec_str = ft_strjoin(", COLLECTIBLE REMAINING :", temp);
	free (temp);
	result = ft_strjoin(step_str, collec_str);
	mlx_string_put(g->vars->mlx, g->vars->win, 10, 10, 16777215, result);
	free (step_str);
	free (collec_str);
	free (result);
	return (0);
}
