/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:26:25 by tmouche           #+#    #+#             */
/*   Updated: 2024/01/25 14:47:43 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"


char	*ft_strjoin_cust(char *s1, char *s2)
{
	char	*dest;
	size_t	index;
	size_t	index2;

	dest = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
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
		free(s1);
	}
	index2 = 0;
	while (s2[index2])
		dest[index++] = s2[index2++];
	free(s2);
	return (dest);
}

char	*ft_give_step(int collec, int step)
{
	char	*str;
	char	*result;
	char 	*res2;

	str = "STEP : ";
	result = NULL;
	result = ft_strjoin(str, ft_itoa(step / 3));
	str = NULL;
	str = ", COLLECTIBLE REMAINING :";
	res2 = ft_strjoin(str, ft_itoa(collec));
	return(ft_strjoin_cust(result, res2));
}
