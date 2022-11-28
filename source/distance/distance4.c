/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ft_s_vertical_x(t_cub *c, double step)
{
	int	quart;

	quart = ft_coord_quart(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 1 || quart == 4 || quart == 41)
	{
		if (ceil(c->pl_board_x / (SIZE / 1.0)) * SIZE == c->pl_board_x)
			return (c->pl_board_x + SIZE);
		return (ceil(c->pl_board_x / (SIZE / 1.0)) * SIZE);
	}
	if (floor(c->pl_board_x / (SIZE / 1.0)) * SIZE == c->pl_board_x)
		return (c->pl_board_x - SIZE);
	return (floor(c->pl_board_x / (SIZE / 1.0)) * SIZE);
}

double	ft_s_vertical_y(t_cub *c, double step)
{
	int		quart;
	double	sharp_radian;

	quart = ft_coord_quart(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	sharp_radian = ft_ray_sharp_radian(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 1 || quart == 2 || quart == 12)
		return (c->pl_board_y - c->s_dist_x * sin(sharp_radian));
	return (c->pl_board_y + c->s_dist_x * sin(sharp_radian));
}

double	ft_s_horizon_x(t_cub *c, double step)
{
	int		quart;
	double	sharp_radian;

	quart = ft_coord_quart(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	sharp_radian = ft_ray_sharp_radian(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 2 || quart == 3 || quart == 23)
		return (c->pl_board_x - c->s_dist_y * cos(sharp_radian));
	return (c->pl_board_x + c->s_dist_y * cos(sharp_radian));
}

double	ft_s_horizon_y(t_cub *c, double step)
{
	int	quart;

	quart = ft_coord_quart(\
				ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 3 || quart == 4 || quart == 34)
	{
		if (ceil(c->pl_board_y / (SIZE / 1.0)) * SIZE == c->pl_board_y)
			return (c->pl_board_y + SIZE);
		return (ceil(c->pl_board_y / (SIZE / 1.0)) * SIZE);
	}
	if (floor(c->pl_board_y / (SIZE / 1.0)) * SIZE == c->pl_board_y)
		return (c->pl_board_y - SIZE);
	return (floor(c->pl_board_y / (SIZE / 1.0)) * SIZE);
}
