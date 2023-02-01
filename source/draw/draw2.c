/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_line_height(t_cub *c)
{
	double	tmp;
	int		line_height;

	tmp = c->h_win / ((c->ray_projection * WALL_HEIGHT_RATIO) / (SIZE / 1.0));
	line_height = (int)tmp;
	return (line_height);
}

int	ft_line_point(t_cub *c, int line_height, char *place)
{
	if (place[0] == 's')
		return ((c->h_win - line_height) / 2);
	if (place[0] == 'e')
		return (c->h_win - ((c->h_win - line_height) / 2));
	return (-1);
}

static void	ft_draw_wall_line(t_cub *c, int x)
{
	int	y;
	int	line_height;
	int	start;
	int	end;
	int	color;

	line_height = ft_line_height(c);
	start = ft_line_point(c, line_height, "start");
	y = ft_max(-1, start - 1);
	end = ft_line_point(c, line_height, "end");
	while (++y < end && y < c->h_win)
	{
		color = ft_xpm_color_wall(c, start, end, y);
		if (color < 0)
			continue ;
		my_mlx_pixel_put(c, x, y, color);
	}
}

void	ft_draw_wall_by_map(t_cub *c, int map_flag)
{
	double	step;
	int		i;

	step = c->fov / (WIDTH_WINDOW - 1);
	i = -1;
	while (++i < WIDTH_WINDOW)
	{
		c->step = step * i;
		ft_ray_cast(c, step * i, map_flag);
		ft_draw_wall_line(c, i);
		ft_draw_sprites(c, i);
		ft_free_sprt_list(c);
	}
	ft_animation_speed(c);
	ft_draw_red_arrow(c);
	ft_draw_minimap(c);
	mlx_put_image_to_window(c->mlx, c->win, c->img, 0, 0);
}
