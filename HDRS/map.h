/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:12:27 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/03 20:31:47 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "structure.h"

int		_random(int seed, int proba);
char	**_copy_map(char **src);
void	_write_err(int err);

void	_fixer_map(t_struct *g);

int		_map_checker(t_map *info, char **map);

char	*_strjoin_map(char *s1, char *s2);
int		_strlen_cust(char *str, char sep);

char	**_read_map(int fd);

#endif