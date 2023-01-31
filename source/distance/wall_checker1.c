/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall-checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_north_east(double *x, double *y)
{
	if (fmod(*x, SIZE / 1.0) == 0)
	{
		(*x) = (*x) / SIZE;
		(*y) = floor((*y) / SIZE);
	}
	else
	{
		(*x) = floor((*x) / SIZE);
		(*y) = ((*y) - SIZE) / SIZE;
	}
}

static void	ft_north_west(double *x, double *y)
{
	if (fmod(*x, SIZE / 1.0) == 0)
	{
		(*x) = ((*x) - SIZE) / SIZE;
		(*y) = floor((*y) / SIZE);
	}
	else
	{
		(*x) = floor((*x) / SIZE);
		(*y) = ((*y) - SIZE) / SIZE;
	}
}

static void	ft_south_west(double *x, double *y)
{
	if (fmod(*x, SIZE / 1.0) == 0)
	{
		(*x) = ((*x) - SIZE) / SIZE;
		(*y) = floor((*y) / SIZE);
	}
	else
	{
		(*x) = floor((*x) / SIZE);
		(*y) = (*y) / SIZE;
	}
}

static void	ft_south_east(double *x, double *y)
{
	if (fmod(*x, SIZE / 1.0) == 0)
	{
		(*x) = (*x) / SIZE;
		(*y) = floor((*y) / SIZE);
	}
	else
	{
		(*x) = floor((*x) / SIZE);
		(*y) = (*y) / SIZE;
	}
}

int	ft_iswall(t_cub *c, double x, double y, int flag)
{
	int		i;
	int		j;
	char	**map;

	map = ft_select_map(c, flag);
	if (ft_iswall_util(c, x, y, flag))
		return (1);
	if (c->compass_x == 'E' && c->compass_y == 'N')
		ft_north_east(&x, &y);
	else if (c->compass_x == 'W' && c->compass_y == 'N')
		ft_north_west(&x, &y);
	else if (c->compass_x == 'W' && c->compass_y == 'S')
		ft_south_west(&x, &y);
	else
		ft_south_east(&x, &y);
	i = (int)y;
	j = (int)x;
	if (i < 0 || j < 0)
		return (0);
	ft_create_sprt_list(c, i, j);
	if (ft_strchr(WALL_OR_DOOR, map[i][j]))
		return (ft_wall_or_door_set(c, map[i][j]));
	return (0);
}
