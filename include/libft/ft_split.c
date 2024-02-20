/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:26:32 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/15 13:41:54 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_hmword(const char *s, char c)
{
	size_t	i;
	size_t	howmanyword;

	howmanyword = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			howmanyword++;
			while (s[i] != c && s[i + 1])
				i++;
		}
		i++;
	}
	return (howmanyword);
}

static size_t	ft_tonextsep(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	if (s[i])
	{
		while (s[i] != c && s[i] != 0)
		{
			len++;
			i++;
		}
		len++;
	}
	return (len);
}

static char	**ft_freetab(char **tab, size_t count)
{
	size_t	i;

	i = -1;
	while (++i < count)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static size_t	ft_fulltab(size_t i, char *tab, const char *s, char c)
{
	size_t	index;

	index = 0;
	while (s[i] && s[i] != c)
		tab[index++] = s[i++];
	tab[index] = 0;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	count;

	tab = ft_calloc(ft_hmword(s, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			tab[count] = malloc(sizeof(char) * ft_tonextsep(s, c, i));
			if (!tab[count])
				return (ft_freetab(tab, count));
			i = ft_fulltab(i, tab[count++], s, c);
		}
	}
	tab[count] = 0;
	return (tab);
}
