/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:47 by tmouche           #+#    #+#             */
/*   Updated: 2024/01/29 18:19:45 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_map.h"
# include "../libft/libft.h"
#include <unistd.h>

void	ft_map_struct(t_map *info, int x1, int x2, int collect)
{
	static t_proj proj;
	
	info->map_width = x2;
	info->map_height = x1;
	info->collect = collect;
	info->step = 0;
	info->vec = 1;
	info->player_state = 0;
	info->mv_x = 0;
	info->mv_y = 0;
	info->proj = &proj;
	info->proj->limit = 0;
	info->proj->i = 0;
	info->proj->o_x1 = 0;
	info->proj->o_x2 = 0;
}

void	ft_freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	ft_strlen_cust(char *str, char sep)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != sep)
		i++;
	if (str[i] == sep)
		i++;
	return (i);
}

char	*ft_strjoin_map(char *s1, char *s2)
{
	char	*dest;
	int	index;
	int	index2;

	dest = ft_calloc(1, ft_strlen_cust(s1, 0) + ft_strlen_cust(s2, 0) + 1);
	if (!dest)
		return (free(s1), NULL);
	index = 0;
	if (s1)
	{
		while (s1[index])
		{
			dest[index] = s1[index];
			index++;
		}
		free (s1);
	}
	index2 = 0;
	while (s2[index2])
		dest[index++] = s2[index2++];
	return (dest);
}
