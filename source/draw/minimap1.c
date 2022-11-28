/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_draw_minimap_background(t_cub *c, int start, int end)
{
	int	x;
	int	y;

	y = start;
	while (++y <= end)
	{
		x = start;
		while (++x <= end)
		{
			if (y == start + 1 || x == start + 1 || y == end || x == end)
				my_mlx_pixel_put(c, x, y, 0x0);
			else
				my_mlx_pixel_put(c, x, y, 0xBFBFBF);
		}
	}
}

static void	ft_draw_frame(t_cub *c, int x, int y)
{
	if (minimap.i >= 0 && minimap.j >= 0 && \
		minimap.i < c->h_map && minimap.j < c->w_map)
	{
		if (c->map[minimap.i][minimap.j] == '1')
			my_mlx_pixel_put(c, x, y, 0x0);
		else if (c->map[minimap.i][minimap.j] == '2' || \
			c->map[minimap.i][minimap.j] == '3' || \
			c->map[minimap.i][minimap.j] == '4')
			my_mlx_pixel_put(c, x, y, 0x757171);
		else if (minimap.i == (int)(c->pl_board_y / SIZE) && \
					minimap.j == (int)(c->pl_board_x / SIZE))
		{
			if (minimap.pl_x == -1)
				minimap.pl_x = x;
			if (minimap.pl_y == -1)
				minimap.pl_y = y;
		}
	}
}

static void	ft_draw_minimap_walls(t_cub *c, int start, int end)
{
	int		x;
	int		y;

	minimap.start_x = c->pl_board_x - (end - start) * MINIMAP_STEP / 2;
	minimap.start_y = c->pl_board_y - (end - start) * MINIMAP_STEP / 2;
	y = start + 1;
	while (++y < end)
	{
		minimap.i = (int)((minimap.start_y + \
					(y - start - 2) * MINIMAP_STEP) / SIZE);
		x = start + 1;
		while (++x <= end)
		{
			minimap.j = (int)((minimap.start_x + \
					(x - start - 2) * MINIMAP_STEP) / SIZE);
			ft_draw_frame(c, x, y);
		}
	}
}

void	ft_draw_minimap(t_cub *c)
{
	int	start;
	int	end;

	start = HEIGHT_WINDOW / (MINIMAP_RATIO * 10);
	end = start + HEIGHT_WINDOW / MINIMAP_RATIO;
	if (end >= HEIGHT_WINDOW || end >= WIDTH_WINDOW)
		return ;
	ft_draw_minimap_background(c, start, end);
	ft_draw_minimap_walls(c, start, end);
	ft_draw_player(c);
}
