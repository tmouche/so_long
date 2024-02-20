/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:32:26 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 13:48:33 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "structure.h"

void	ft_write_err(int err);
void	ft_reset_map(char **map);
void	ft_set_map(t_map *info);
int		ft_map_checker(t_map *map_info, char **map);

#endif
