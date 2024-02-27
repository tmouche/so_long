/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:56:51 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/27 19:17:32 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "structure.h"

int		_pix_x(size_t x);
int		_pix_y(size_t y);

int		_key_release(int keycode, t_struct *g);
int		_key_press(int keycode, t_struct *g);

void	_window(t_struct *glob);

#endif