/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall-checker2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_wall_or_door(char **map, int i, int j)
{
	if (map[i - 1][j - 1] == '2' || map[i - 1][j - 0] == '2' || \
		map[i - 0][j - 1] == '2' || map[i - 0][j - 0] == '2')
		return (2);
	if (map[i - 1][j - 1] == '3' || map[i - 1][j - 0] == '3' || \
		map[i - 0][j - 1] == '3' || map[i - 0][j - 0] == '3')
		return (3);
	if (map[i - 1][j - 1] == '4' || map[i - 1][j - 0] == '4' || \
		map[i - 0][j - 1] == '4' || map[i - 0][j - 0] == '4')
		return (4);
	if (map[i - 1][j - 1] == '1' || map[i - 1][j - 0] == '1' || \
		map[i - 0][j - 1] == '1' || map[i - 0][j - 0] == '1')
		return (1);
	return (0);
}

int	ft_wall_or_door_set(t_cub *c, char chr)
{
	if (chr == '1' || chr == '2' || chr == '3' || chr == '4')
		c->w_or_d = (int)chr - 48;
	return (1);
}

char	**ft_select_map(t_cub *c, int flag)
{
	if (flag == 2)
		return (c->map);
	return (c->init_map);
}

int	ft_iswall_util(t_cub *c, double x, double y, int flag)
{
	int		i;
	int		j;
	char	**map;

	map = ft_select_map(c, flag);
	if (fmod(x, SIZE) == 0 && fmod(y, SIZE) == 0)
	{
		i = (int)y;
		j = (int)x;
		i /= SIZE;
		j /= SIZE;
		if (ft_strchr(WALL_OR_DOOR, map[i - 1][j - 1]) || \
			ft_strchr(WALL_OR_DOOR, map[i - 1][j - 0]) || \
			ft_strchr(WALL_OR_DOOR, map[i - 0][j - 1]) || \
			ft_strchr(WALL_OR_DOOR, map[i - 0][j - 0]))
		{
			c->w_or_d = ft_wall_or_door(map, i, j);
			return (1);
		}
	}
	return (0);
}
