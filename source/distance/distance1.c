/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ft_cntr_rad(t_cub *c)
{
	if (c->dir_vec_x == 0 && c->dir_vec_y == -1)
		c->cntr_rad = M_PI_2;
	else if (c->dir_vec_x == -1 && c->dir_vec_y == 0)
		c->cntr_rad = M_PI;
	else if (c->dir_vec_x == 0 && c->dir_vec_y == 1)
		c->cntr_rad = M_PI + M_PI_2;
	else if (c->dir_vec_x == 1 && c->dir_vec_y == 0)
		c->cntr_rad = 0;
	else
	{
		if (c->dir_vec_x > 0 && c->dir_vec_y < 0)
			c->cntr_rad = atan(-1 * (c->dir_vec_y / c->dir_vec_x));
		if (c->dir_vec_x < 0 && c->dir_vec_y < 0)
			c->cntr_rad = M_PI - atan(1 * (c->dir_vec_y / c->dir_vec_x));
		if (c->dir_vec_x < 0 && c->dir_vec_y > 0)
			c->cntr_rad = M_PI + atan(-1 * (c->dir_vec_y / c->dir_vec_x));
		if (c->dir_vec_x > 0 && c->dir_vec_y > 0)
			c->cntr_rad = 2 * M_PI - atan(1 * (c->dir_vec_y / c->dir_vec_x));
	}
	return (c->cntr_rad);
}

int	ft_coord_quart(double radian)
{
	radian = ft_correct_radian(radian);
	if (radian == M_PI_2)
		return (12);
	if (radian == M_PI)
		return (23);
	if (radian == M_PI + M_PI_2)
		return (34);
	if (radian == 0 || radian == 2 * M_PI)
		return (41);
	if (radian > 0 && radian < M_PI_2)
		return (1);
	if (radian > M_PI_2 && radian < M_PI)
		return (2);
	if (radian > M_PI && radian < M_PI + M_PI_2)
		return (3);
	if (radian > M_PI + M_PI_2 && radian < 2 * M_PI)
		return (4);
	return (0);
}

static void	ft_side_dist_xy_util(t_cub *c, double step)
{
	double	a;
	int		quart;

	a = ft_correct_radian(c->cntr_rad + c->fov / 2 - step);
	quart = ft_coord_quart(a);
	if (quart == 1)
	{
		c->s_dist_x = (SIZE - fmod(c->pl_board_x, SIZE)) / cos(a);
		c->s_dist_y = (fmod(c->pl_board_y, SIZE)) / sin(a);
	}
	else if (quart == 2)
	{
		c->s_dist_x = (fmod(c->pl_board_x, SIZE)) / cos(M_PI - a);
		c->s_dist_y = (fmod(c->pl_board_y, SIZE)) / sin (M_PI - a);
	}
	else if (quart == 3)
	{
		c->s_dist_x = (fmod(c->pl_board_x, SIZE)) / cos(a - M_PI);
		c->s_dist_y = (SIZE - fmod(c->pl_board_y, SIZE)) / sin (a - M_PI);
	}
	else if (quart == 4)
	{
		c->s_dist_x = (SIZE - fmod(c->pl_board_x, SIZE)) / cos(2 * M_PI - a);
		c->s_dist_y = (SIZE - fmod(c->pl_board_y, SIZE)) / sin (2 * M_PI - a);
	}
}

void	ft_side_dist_xy(t_cub *c, double step)
{
	int	quart;

	quart = ft_coord_quart(ft_correct_radian(c->cntr_rad + c->fov / 2 - step));
	if (quart == 12)
	{
		c->s_dist_x = SIZE_MAX;
		c->s_dist_y = fmod(c->pl_board_y, SIZE);
	}
	else if (quart == 23)
	{
		c->s_dist_x = fmod(c->pl_board_x, SIZE);
		c->s_dist_y = SIZE_MAX;
	}
	else if (quart == 34)
	{
		c->s_dist_x = SIZE_MAX;
		c->s_dist_y = SIZE - fmod(c->pl_board_y, SIZE);
	}
	else if (quart == 41)
	{
		c->s_dist_x = SIZE - fmod(c->pl_board_x, SIZE);
		c->s_dist_y = SIZE_MAX;
	}
	else
		ft_side_dist_xy_util(c, step);
}
