/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <vkhlghat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:46:00 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/04/11 18:57:00 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	**tabfree(char **tab)
{
	int	i;

	if (!tab)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

static int	wordcount(const char *s, char c)
{
	int	q;
	int	i;

	q = 1;
	if (!s[0] || s[0] == c)
		q = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && i > 0 && s[i - 1] == c)
			q++;
		i++;
	}
	return (q);
}

static int	wordlen(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free_str(char **tab, char *str)
{
	free(str);
	return (tab);
}

char	**ft_split_free(char *s, char c, char *tmp, int i)
{
	char	**tab;
	int		wc;
	int		j;

	if (!s)
		return (NULL);
	tmp = s;
	wc = wordcount(s, c);
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!tab)
		return (NULL);
	while (++i < wc)
	{
		tab[i] = (char *)malloc(sizeof(char) * (wordlen(s, c) + 1));
		if (!tab[i])
			return (tabfree(tab));
		while (*s == c)
			s++;
		j = 0;
		while (*s != c && *s)
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (ft_free_str(tab, tmp));
}
