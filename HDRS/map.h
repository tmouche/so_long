/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:12:27 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 16:19:17 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "structure.h"

int		_random(int seed, int proba);
void	_fixer_map(t_map *info, t_opps **bad);

void	_reset_map(char **map);
void	_write_err(int err);

int		_map_checker(t_map *info, char **map);

void	_map_struct(t_map *info, int x1, int x2, int collect);
char	*_strjoin_map(char *s1, char *s2);
int		_strlen_cust(char *str, char sep);
void	_freemap(char **map);

char	**_read_map(int fd);

#endif