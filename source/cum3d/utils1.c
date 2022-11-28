/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_error(char *message, int exit_code)
{
	if (message)
	{
		write(2, RED, ft_strlen(RED));
		write(2, "Error: ", ft_strlen("Error: "));
		write(2, message, ft_strlen(message));
		write(2, RESET, ft_strlen(RESET));
	}
	if (exit_code)
		exit(exit_code);
}

char	*ft_strfree(char *str)
{
	if (!str)
		return (NULL);
	free(str);
	return (NULL);
}

char	*ft_strfree2(char *str1, char *str2)
{
	ft_strfree(str1);
	ft_strfree(str2);
	return (NULL);
}

char	**ft_arrfree(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (NULL);
}
