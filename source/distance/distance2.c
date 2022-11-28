/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_delta_dist_xy_util(t_cub *c, double step)
{
	double	angle;
	int		quart;

	angle = ft_correct_radian(c->cntr_rad + c->fov / 2 - step);
	quart = ft_coord_quart(angle);
	if (quart == 1)
	{
		c->d_dist_x = SIZE / cos(angle);
		c->d_dist_y = SIZE / sin(angle);
	}
	else if (quart == 2)
	{
		c->d_dist_x = SIZE / cos(M_PI - angle);
		c->d_dist_y = SIZE / sin (M_PI - angle);
	}
	else if (quart == 3)
	{
		c->d_dist_x = SIZE / cos(angle - M_PI);
		c->d_dist_y = SIZE / sin (angle - M_PI);
	}
	else if (quart == 4)
	{
		c->d_dist_x = SIZE / cos(2 * M_PI - angle);
		c->d_dist_y = SIZE / sin (2 * M_PI - angle);
	}
}

void	ft_delta_dist_xy(t_cub *c, double step)
{
	int	quart;

	quart = ft_coord_quart(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 12 || quart == 34)
	{
		c->d_dist_x = SIZE_MAX;
		c->d_dist_y = SIZE;
	}
	else if (quart == 23 || quart == 41)
	{
		c->d_dist_x = SIZE;
		c->d_dist_y = SIZE_MAX;
	}
	else
		ft_delta_dist_xy_util(c, step);
}

void	ft_crossing_direction_with_map(t_cub *c, double step)
{
	int	quart;

	quart = ft_coord_quart(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 1 || quart == 12)
	{
		c->compass_x = 'E';
		c->compass_y = 'N';
	}
	else if (quart == 2 || quart == 23)
	{
		c->compass_x = 'W';
		c->compass_y = 'N';
	}
	else if (quart == 3 || quart == 34)
	{
		c->compass_x = 'W';
		c->compass_y = 'S';
	}
	else if (quart == 4 || quart == 41)
	{
		c->compass_x = 'E';
		c->compass_y = 'S';
	}
}
