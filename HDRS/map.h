/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:12:27 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 20:07:10 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "structure.h"

int		_random(int seed, int proba);
char	**_copy_map(char **src);
void	_write_err(int err);
void	_check_char(char **map, char c);

void	_init_t_map(t_map *info, int x1, int x2);
void	_init_map_block(t_map *info);

void	_fixer_map(t_struct *g);

int		_map_checker(t_map *info, char **map);
void	_map_check_path(t_map *info, char **map);

char	**_read_map(char *path);

#endif