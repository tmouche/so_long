/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:01:00 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/03 17:01:40 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include <stdlib.h>

static void	_free_texture_c(t_colors *colors)
{
	if (colors->explosion_3)
		free (colors->explosion_3);
	if (colors->explosion_4)
		free (colors->explosion_4);
	if (colors->explosion_5)
		free (colors->explosion_5);
	if (colors->explosion_6)
		free (colors->explosion_6);
	if (colors->laser_1_r)
		free (colors->laser_1_r);
	if (colors->laser_2_r)
		free (colors->laser_2_r);
	if (colors->laser_3_r)
		free (colors->laser_3_r);
}

static void	_free_texture_b(t_colors *colors)
{
	if (colors->p_shoot2_l)
		free (colors->p_shoot2_l);
	if (colors->p_shoot3_l)
		free (colors->p_shoot3_l);
	if (colors->p_shoot4_l)
		free (colors->p_shoot4_l);
	if (colors->p_shoot5_l)
		free (colors->p_shoot5_l);
	if (colors->p_shoot1_r)
		free (colors->p_shoot1_r);
	if (colors->p_shoot2_r)
		free (colors->p_shoot2_r);
	if (colors->p_shoot3_r)
		free (colors->p_shoot3_r);
	if (colors->p_shoot4_r)
		free (colors->p_shoot4_r);
	if (colors->p_shoot5_r)
		free (colors->p_shoot5_r);
	if (colors->explosion_1)
		free (colors->explosion_1);
	if (colors->explosion_2)
		free (colors->explosion_2);
	_free_texture_c(colors);
}

void	_free_texture_a(t_colors *colors)
{
	if (colors->p_l)
		free (colors->p_l);
	if (colors->p_r)
		free (colors->p_r);
	if (colors->opps_bot)
		free (colors->opps_bot);
	if (colors->opps_mid)
		free (colors->opps_mid);
	if (colors->opps_top)
		free (colors->opps_top);
	if (colors->collect)
		free (colors->collect);
	if (colors->door)
		free (colors->door);
	if (colors->empty)
		free (colors->empty);
	if (colors->wall)
		free (colors->wall);
	if (colors->p_shoot1_l)
		free (colors->p_shoot1_l);
	_free_texture_b(colors);
}