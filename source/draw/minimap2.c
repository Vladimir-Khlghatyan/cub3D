/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_set_minimap_pl_delta_util(int kx, int ky)
{
	minimap.pl_delta_x = ((SIZE / MINIMAP_STEP) / 3) * kx;
	minimap.pl_delta_y = ((SIZE / MINIMAP_STEP) / 3) * ky;
}

static void	ft_set_minimap_pl_delta(t_cub *c)
{
	double	cr;

	cr = ft_correct_radian(c->cntr_rad);
	if (cr >= M_PI_2 + atan(1.0 / 3) && cr < M_PI - atan(1.0 / 3))
		ft_set_minimap_pl_delta_util(0, 0);
	else if (cr >= M_PI - atan(1.0 / 3) && cr < M_PI + atan(1.0 / 3))
		ft_set_minimap_pl_delta_util(0, 1);
	else if (cr >= M_PI + atan(1.0 / 3) && cr < M_PI + atan(3))
		ft_set_minimap_pl_delta_util(0, 2);
	else if (cr >= M_PI + atan(3) && cr < 2 * M_PI - atan(3))
		ft_set_minimap_pl_delta_util(1, 2);
	else if (cr >= 2 * M_PI - atan(3) && cr < 2 * M_PI - atan(1.0 / 3))
		ft_set_minimap_pl_delta_util(2, 2);
	else if (cr >= 2 * M_PI - atan(1.0 / 3) || cr < atan(1.0 / 3))
		ft_set_minimap_pl_delta_util(2, 1);
	else if (cr >= atan(1.0 / 3) && cr < atan(3))
		ft_set_minimap_pl_delta_util(2, 0);
	else if (cr >= atan(3) && cr < M_PI_2 + atan(1.0 / 3))
		ft_set_minimap_pl_delta_util(1, 0);
}

void	ft_draw_player(t_cub *c)
{
	int	x;
	int	y;
	int	end[2];

	ft_set_minimap_pl_delta(c);
	y = minimap.pl_y - 1;
	end[0] = minimap.pl_y + SIZE / MINIMAP_STEP;
	end[1] = minimap.pl_x + SIZE / MINIMAP_STEP;
	while (++y < end[0])
	{
		x = minimap.pl_x - 1;
		while (++x < end[1])
			my_mlx_pixel_put(c, x, y, 0x0000FF);
	}
	y = minimap.pl_y + minimap.pl_delta_y - 1;
	end[0] = minimap.pl_y + minimap.pl_delta_y + (SIZE / MINIMAP_STEP) / 3;
	end[1] = minimap.pl_x + minimap.pl_delta_x + (SIZE / MINIMAP_STEP) / 3;
	while (++y < end[0])
	{
		x = minimap.pl_x + minimap.pl_delta_x - 1;
		while (++x < end[1])
			my_mlx_pixel_put(c, x, y, 0xFF0000);
	}
	minimap.pl_delta_x = -1;
	minimap.pl_delta_y = -1;
}
