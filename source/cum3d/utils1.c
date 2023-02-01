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

int	ft_error(t_cub *c, char *message, int exit_code)
{
	if (message)
	{
		write(2, RED, ft_strlen(RED));
		write(2, "Error: ", ft_strlen("Error: "));
		write(2, message, ft_strlen(message));
		write(2, RESET, ft_strlen(RESET));
	}
	if (c)
	{
		if (c->win)
			mlx_destroy_window(c->mlx, c->win);
		ft_arrfree(c->init_map);
		ft_arrfree(c->map);
		free(c->xpm);
		ft_free_sprt_list(c);
		free(c);
	}
	if (exit_code)
		exit(exit_code);
	return (exit_code);
}

void	ft_strfree(char *str)
{
	if (!str)
		return ;
	free(str);
	str = NULL;
}

void	ft_strfree2(char *str1, char *str2)
{
	ft_strfree(str1);
	ft_strfree(str2);
}

char	**ft_arrfree(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}
