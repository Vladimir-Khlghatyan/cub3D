/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:45:20 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/13 23:47:11 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	s_len = ft_strlen(s);
	if (s_len < start)
	{
		substr = (char *)malloc(sizeof(char) * 1);
		substr[0] = '\0';
		return (substr);
	}
	if (s_len - start >= len)
		substr = (char *)malloc(sizeof(char) * (len + 1));
	else
		substr = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i])
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}
