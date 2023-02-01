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

double	ft_max(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}

char	**ft_copy_map(t_cub *c, char **map)
{
	int		len;
	int		i;
	char	**new_map;

	if (!map)
		return (NULL);
	len = ft_arrlen(map);
	new_map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_map)
		ft_error(c, "something went wrong with malloc, try again!\n", 1);
	i = -1;
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	new_map[i] = NULL;
	return (new_map);
}

void	ft_reset_map(t_cub *c)
{
	int	i;
	int	j;

	if (!c->init_map || !c->map)
		return ;
	if (c->door_is_open == 1 && \
		way_length.forward_for_door > 2 * DOOR_OPEN_DIST)
	{
		i = -1;
		while (c->init_map[++i])
		{
			j = -1;
			while (c->init_map[i][++j])
				c->map[i][j] = c->init_map[i][j];
		}
		c->door_is_open = 0;
	}
}
