/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:20:42 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/11/02 18:36:51 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//	The ft_strstr() function checks if each "str" character is in "set".
//
// RETURN VALUES
//	The ft_strstr() function returns 1, if each "str" character is in "set",
//	otherwise, function returns 0.

#include "cub.h"

int	ft_strset(char *str, char *set)
{
	int	i;

	if (!str || !set)
		return (0);
	i = -1;
	while (str[++i])
		if (!ft_strchr(set, str[i]))
			return (0);
	return (1);
}
