/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:22:36 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/04/01 14:09:55 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while ((s1[++i] || s2[i]) && (i < n))
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
	}
	return (0);
}
