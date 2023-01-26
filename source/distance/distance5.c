/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ft_d_vertical_x(t_cub *c, double step)
{
	int	quart;

	quart = ft_coord_quart(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 1 || quart == 4 || quart == 41)
		return (SIZE);
	if (quart == 2 || quart == 3 || quart == 23)
		return (-SIZE);
	return (0);
}

double	ft_d_vertical_y(t_cub *c, double step)
{
	int		quart;
	double	sharp_radian;

	quart = ft_coord_quart(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	sharp_radian = ft_ray_sharp_radian(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 1 || quart == 2 || quart == 12)
		return (-1 * c->d_dist_x * sin(sharp_radian));
	return (c->d_dist_x * sin(sharp_radian));
}

double	ft_d_horizon_x(t_cub *c, double step)
{
	int		quart;
	double	sharp_radian;

	quart = ft_coord_quart(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	sharp_radian = ft_ray_sharp_radian(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 2 || quart == 3 || quart == 23)
		return (-1 * c->d_dist_y * cos(sharp_radian));
	return (c->d_dist_y * cos(sharp_radian));
}

double	ft_d_horizon_y(t_cub *c, double step)
{
	int	quart;

	quart = ft_coord_quart(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 3 || quart == 4 || quart == 34)
		return (SIZE);
	if (quart == 1 || quart == 2 || quart == 12)
		return (-SIZE);
	return (0);
}
