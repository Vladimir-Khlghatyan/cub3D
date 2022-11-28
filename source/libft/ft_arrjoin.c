/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:22:57 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/14 17:09:50 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**ft_arrjoin(char **arr1, char **arr2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	**arr;

	len1 = ft_arrlen(arr1);
	len2 = ft_arrlen(arr2);
	arr = (char **)malloc(sizeof(char *) * (len1 + len2 + 1));
	if (!arr)
	{
		ft_arrfree(arr1);
		ft_arrfree(arr2);
		return (NULL);
	}
	i = -1;
	while (++i < len1)
		arr[i] = arr1[i];
	j = -1;
	while (++j < len2)
		arr[i + j] = arr2[j];
	arr[i + j] = NULL;
	free(arr1);
	free(arr2);
	return (arr);
}
