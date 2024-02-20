/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:12:27 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 13:48:30 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "structure.h"

void	ft_map_struct(t_map *info, int x1, int x2, int collect);
void	ft_freemap(char **map);
int		ft_strlen_cust(char *str, char sep);
int		ft_random(int seed, int proba);
char	*ft_strjoin_map(char *s1, char *s2);
char	**ft_map_dup(t_map *info);
char	**read_map(int fd);
int		ft_pos_opps(t_opps **bad, int x1, int x2);
void	_kill_opps(t_opps *bad, int x1, int x2);

void	_lstadd_front(t_opps **lst, t_opps *new);
int		_lstadd_back(t_opps **lst, t_opps *new);
void	_lstclear(t_opps **lst);
t_opps	*_lstnew(int x1, int x2);
t_opps	*_lstlast(t_opps *lst);
int		_lstsize(t_opps *lst);

#endif