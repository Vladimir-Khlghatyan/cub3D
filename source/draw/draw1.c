/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_cub *c, int x, int y, int color)
{
	char	*dst;

	dst = c->addr + (y * c->line_length + x * (c->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_get_xmp_pixel_color(t_xpm xpm, int x, int y)
{
	char	*dst;

	dst = xpm.addr + (y * xpm.linelen + x * (xpm.bpp / 8));
	return (*(unsigned int *)dst);
}

int	ft_draw_floor_and_ceilling(t_cub *c)
{
	int	x;
	int	y;

	y = -1;
	while (++y < c->h_win)
	{
		x = -1;
		while (++x < c->w_win)
		{
			if (y <= c->h_win / 2)
				my_mlx_pixel_put(c, x, y, c->ceiling_clr);
			else
				my_mlx_pixel_put(c, x, y, c->floor_clr);
		}
	}
	return (0);
}

int	ft_draw_red_arrow(t_cub *c)
{
	int	x;
	int	y;
	int	line;
	int	end;

	line = 51;
	y = c->h_win;
	while (--y >= 0 && line > 0)
	{
		x = (c->w_win - line) / 2 - 1;
		end = x + line;
		line -= 2;
		while (++x >= 0 && x <= end)
			my_mlx_pixel_put(c, x, y, 0xFF0000);
	}
	return (0);
}
