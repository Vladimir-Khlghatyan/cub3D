/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_ray_projection(t_cub *c, double step, int flag)
{
	double	angle;

	angle = ft_correct_radian(c->cntr_rad + c->fov / 2 - step);
	angle = fabs(angle - c->cntr_rad);
	ft_ray_length(c, step, flag);
	c->ray_projection = c->ray_length * cos(angle);
}

double	ft_ray_cast(t_cub *c, double step, int flag)
{
	ft_cntr_rad(c);
	ft_crossing_direction_with_map(c, step);
	ft_side_dist_xy(c, step);
	ft_delta_dist_xy(c, step);
	ft_ray_projection(c, step, flag);
	return (c->ray_length);
}
