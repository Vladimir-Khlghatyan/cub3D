/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:55:26 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/14 21:11:39 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**ft_arrtrim(char **arr, char *set)
{
	int		i;
	char	*tmp;

	if (!arr)
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		tmp = ft_strtrim(arr[i], set);
		free(arr[i]);
		arr[i] = tmp;
	}
	return (arr);
}
