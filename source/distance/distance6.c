/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_d_dist_x_part(t_cub *c, double step, int flag)
{
	if (vertical.ray_length + c->d_dist_x > horizon.ray_length + c->d_dist_y)
		return (0);
	vertical.ray_length += fabs(c->d_dist_x);
	vertical.x += ft_d_vertical_x(c, step);
	vertical.y += ft_d_vertical_y(c, step);
	if (ft_iswall(c, vertical.x, vertical.y, flag))
	{
		c->ray_length = vertical.ray_length;
		c->cross_coor_x = vertical.x;
		c->cross_coor_y = vertical.y;
		c->pic = c->compass_x;
		return (1);
	}
	return (0);
}

static int	ft_d_dist_y_part(t_cub *c, double step, int flag)
{
	if (horizon.ray_length + c->d_dist_y > vertical.ray_length + c->d_dist_x)
		return (0);
	horizon.ray_length += fabs(c->d_dist_y);
	horizon.x += ft_d_horizon_x(c, step);
	horizon.y += ft_d_horizon_y(c, step);
	if (ft_iswall(c, horizon.x, horizon.y, flag))
	{
		c->ray_length = horizon.ray_length;
		c->cross_coor_x = horizon.x;
		c->cross_coor_y = horizon.y;
		c->pic = c->compass_y;
		return (1);
	}
	return (0);
}

static int	ft_s_dist_x_part(t_cub *c, double step, int flag)
{
	vertical.ray_length = fabs(c->s_dist_x);
	vertical.x = ft_s_vertical_x(c, step);
	vertical.y = ft_s_vertical_y(c, step);
	if (ft_iswall(c, vertical.x, vertical.y, flag))
	{
		c->ray_length = vertical.ray_length;
		c->cross_coor_x = vertical.x;
		c->cross_coor_y = vertical.y;
		c->pic = c->compass_x;
		return (1);
	}
	while (vertical.ray_length + c->d_dist_x < c->s_dist_y)
		if (ft_d_dist_x_part(c, step, flag))
			return (1);
	return (0);
}

static int	ft_s_dist_y_part(t_cub *c, double step, int flag)
{
	horizon.ray_length = fabs(c->s_dist_y);
	horizon.x = ft_s_horizon_x(c, step);
	horizon.y = ft_s_horizon_y(c, step);
	if (ft_iswall(c, horizon.x, horizon.y, flag))
	{
		c->ray_length = horizon.ray_length;
		c->cross_coor_x = horizon.x;
		c->cross_coor_y = horizon.y;
		c->pic = c->compass_y;
		return (1);
	}
	while (horizon.ray_length + c->d_dist_y < c->s_dist_x)
		if (ft_d_dist_y_part(c, step, flag))
			return (1);
	return (0);
}

void	ft_ray_length(t_cub *c, double step, int flag)
{
	if (c->s_dist_x <= c->s_dist_y)
	{
		if (ft_s_dist_x_part(c, step, flag) || \
			ft_s_dist_y_part(c, step, flag))
			return ;
		while (1)
			if (ft_d_dist_x_part(c, step, flag) || \
				ft_d_dist_y_part(c, step, flag))
				break ;
	}
	else
	{
		if (ft_s_dist_y_part(c, step, flag) || \
			ft_s_dist_x_part(c, step, flag))
			return ;
		while (1)
			if (ft_d_dist_y_part(c, step, flag) || \
				ft_d_dist_x_part(c, step, flag))
				break ;
	}
}
