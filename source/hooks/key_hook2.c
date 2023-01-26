/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_close(t_cub *c)
{
	mlx_destroy_window(c->mlx, c->win);
	ft_arrfree(c->init_map);
	ft_arrfree(c->map);
	free(c->xpm);
	free(c);
	printf("%sGAME OVER.\n Hope you enjoyed it :)\n%s", GREEN, RESET);
	exit(1);
}

void	ft_go_forward(t_cub *c)
{
	int		quart;
	double	sharp_radian;

	quart = ft_coord_quart(way_length.f_radian);
	sharp_radian = ft_ray_sharp_radian(way_length.f_radian);
	if (way_length.forward > DIST_FROM_WALL)
	{
		if (quart == 12)
			c->pl_board_y -= STEP;
		if (quart == 23)
			c->pl_board_x -= STEP;
		if (quart == 34)
			c->pl_board_y += STEP;
		if (quart == 41)
			c->pl_board_x += STEP;
		if (quart == 1 || quart == 4)
			c->pl_board_x += STEP * cos(sharp_radian);
		if (quart == 2 || quart == 3)
			c->pl_board_x -= STEP * cos(sharp_radian);
		if (quart == 1 || quart == 2)
			c->pl_board_y -= STEP * sin(sharp_radian);
		if (quart == 3 || quart == 4)
			c->pl_board_y += STEP * sin(sharp_radian);
	}
}

void	ft_go_back(t_cub *c)
{
	int		quart;
	double	sharp_radian;

	quart = ft_coord_quart(way_length.b_radian);
	sharp_radian = ft_ray_sharp_radian(way_length.b_radian);
	if (way_length.back > DIST_FROM_WALL)
	{
		if (quart == 12)
			c->pl_board_y -= STEP;
		if (quart == 23)
			c->pl_board_x -= STEP;
		if (quart == 34)
			c->pl_board_y += STEP;
		if (quart == 41)
			c->pl_board_x += STEP;
		if (quart == 1 || quart == 4)
			c->pl_board_x += STEP * cos(sharp_radian);
		if (quart == 2 || quart == 3)
			c->pl_board_x -= STEP * cos(sharp_radian);
		if (quart == 1 || quart == 2)
			c->pl_board_y -= STEP * sin(sharp_radian);
		if (quart == 3 || quart == 4)
			c->pl_board_y += STEP * sin(sharp_radian);
	}
}

void	ft_go_left(t_cub *c)
{
	int		quart;
	double	sharp_radian;

	quart = ft_coord_quart(way_length.l_radian);
	sharp_radian = ft_ray_sharp_radian(way_length.l_radian);
	if (way_length.left > DIST_FROM_WALL)
	{
		if (quart == 12)
			c->pl_board_y -= STEP;
		if (quart == 23)
			c->pl_board_x -= STEP;
		if (quart == 34)
			c->pl_board_y += STEP;
		if (quart == 41)
			c->pl_board_x += STEP;
		if (quart == 1 || quart == 4)
			c->pl_board_x += STEP * cos(sharp_radian);
		if (quart == 2 || quart == 3)
			c->pl_board_x -= STEP * cos(sharp_radian);
		if (quart == 1 || quart == 2)
			c->pl_board_y -= STEP * sin(sharp_radian);
		if (quart == 3 || quart == 4)
			c->pl_board_y += STEP * sin(sharp_radian);
	}
}

void	ft_go_right(t_cub *c)
{
	int		quart;
	double	sharp_radian;

	quart = ft_coord_quart(way_length.r_radian);
	sharp_radian = ft_ray_sharp_radian(way_length.r_radian);
	if (way_length.right > DIST_FROM_WALL)
	{
		if (quart == 12)
			c->pl_board_y -= STEP;
		if (quart == 23)
			c->pl_board_x -= STEP;
		if (quart == 34)
			c->pl_board_y += STEP;
		if (quart == 41)
			c->pl_board_x += STEP;
		if (quart == 1 || quart == 4)
			c->pl_board_x += STEP * cos(sharp_radian);
		if (quart == 2 || quart == 3)
			c->pl_board_x -= STEP * cos(sharp_radian);
		if (quart == 1 || quart == 2)
			c->pl_board_y -= STEP * sin(sharp_radian);
		if (quart == 3 || quart == 4)
			c->pl_board_y += STEP * sin(sharp_radian);
	}
}
