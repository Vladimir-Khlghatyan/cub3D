/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_turn_around_util1(t_cub *c, double angle)
{
	if (angle == 0 || angle == 2 * M_PI)
	{
		c->dir_vec_x = 1.0;
		c->dir_vec_y = 0.0;
	}
	else if (angle == M_PI_2)
	{
		c->dir_vec_x = 0.0;
		c->dir_vec_y = -1.0;
	}
	else if (angle == M_PI)
	{
		c->dir_vec_x = -1.0;
		c->dir_vec_y = 0.0;
	}
	else if (angle == M_PI + M_PI_2)
	{
		c->dir_vec_x = 0.0;
		c->dir_vec_y = 1.0;
	}
}

void	ft_turn_around_util2(t_cub *c, double angle)
{
	double	sharp_radian;

	sharp_radian = ft_ray_sharp_radian(angle);
	if (angle > 0 && angle < M_PI_2)
	{
		c->dir_vec_x = cos(sharp_radian);
		c->dir_vec_y = -sin(sharp_radian);
	}
	else if (angle > M_PI_2 && angle < M_PI)
	{
		c->dir_vec_x = -cos(sharp_radian);
		c->dir_vec_y = -sin(sharp_radian);
	}
	else if (angle > M_PI && angle < M_PI + M_PI_2)
	{
		c->dir_vec_x = -cos(sharp_radian);
		c->dir_vec_y = sin(sharp_radian);
	}
	else if (angle > M_PI + M_PI_2 && angle < 2 * M_PI)
	{
		c->dir_vec_x = cos(sharp_radian);
		c->dir_vec_y = sin(sharp_radian);
	}
}

void	ft_turn_around(t_cub *c, int keycode, double acceleration)
{
	double	angle;

	angle = 0;
	if (keycode == KEY_LEFT)
		angle = c->cntr_rad + M_PI / (TURN_AROUND_STEP * acceleration);
	else if (keycode == KEY_RIGHT)
		angle = c->cntr_rad - M_PI / (TURN_AROUND_STEP * acceleration);
	angle = ft_correct_radian(angle);
	ft_turn_around_util1(c, angle);
	ft_turn_around_util2(c, angle);
}

int	key_hook(int keycode, t_cub *c)
{
	if (keycode == KEY_ESC)
		ft_close(c);
	if (keycode == KEY_SPACE && way_length.forward <= DOOR_OPEN_DIST)
	{
		ft_open_door(c);
		c->door_is_open = 1;
	}
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		ft_turn_around(c, keycode, 1);
	if (keycode == KEY_W || keycode == KEY_UP)
		ft_go_forward(c);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_go_back(c);
	if (keycode == KEY_A)
		ft_go_left(c);
	if (keycode == KEY_D)
		ft_go_right(c);
	c->draw_line_flag = 1;
	c->start = -1;
	c->end = WIDTH_WINDOW;
	return (0);
}

void	ft_open_door(t_cub *c)
{
	int		i;
	int		j;

	i = (int)c->pl_board_y;
	j = (int)c->pl_board_x;
	i /= SIZE;
	j /= SIZE;
	if (c->map[i - 1][j] == '2')
		c->map[i - 1][j] = '0';
	if (c->map[i + 1][j] == '2')
		c->map[i + 1][j] = '0';
	if (c->map[i][j - 1] == '2')
		c->map[i][j - 1] = '0';
	if (c->map[i][j + 1] == '2')
		c->map[i][j + 1] = '0';
}
