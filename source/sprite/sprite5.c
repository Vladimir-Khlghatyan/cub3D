/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_xpm_color_sprt(t_cub *c, int start, int end, int win_y)
{
	double	d;
	int		x;
	int		y;
	int		color;

	d = c->sprt_tmp->xpm_x_ratio * c->xpm[c->s_num].width;
	x = (int)d;
	if (end - start <= HEIGHT_WINDOW)
		y = c->xpm[c->s_num].height * (win_y - start) / (end - start);
	else
	{
		y = (c->xpm[c->s_num].height * (end - start) - \
			c->xpm[c->s_num].height * HEIGHT_WINDOW) / (2 * (end - start));
		y = y + (win_y * (c->xpm[c->s_num].height - 2 * y)) / HEIGHT_WINDOW;
	}
	color = ft_get_xmp_pixel_color(c->xpm[c->s_num], x, y);
	return (color);
}

int	ft_sprt_line_height(t_cub *c)
{
	double	tmp;
	int		line_height;

	tmp = c->h_win / ((c->sprt_tmp->sdp * WALL_HEIGHT_RATIO) / (SIZE / 1.0));
	line_height = (int)tmp;
	return (line_height);
}

void	ft_draw_sprt_line(t_cub *c, int x)
{
	int	y;
	int	line_height;
	int	start;
	int	end;
	int	color;

	line_height = ft_sprt_line_height(c);
	start = ft_line_point(c, line_height, "start");
	y = ft_max(-1, start - 1);
	end = ft_line_point(c, line_height, "end");
	while (++y < end && y < c->h_win)
	{
		color = ft_xpm_color_sprt(c, start, end, y);
		if (color < 0)
			continue ;
		my_mlx_pixel_put(c, x, y, color);
	}
}

void	ft_draw_sprites(t_cub *c, int x)
{
	t_sprt	*tmp;

	tmp = c->sprt;
	if (!tmp)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		c->sprt_tmp = tmp;
		ft_draw_sprt_line(c, x);
		tmp = tmp->prev;
	}
}

void	ft_animation_speed(t_cub *c)
{
	c->s_speed++;
	if (c->s_speed == SPRT_ANIM_SPEED)
	{
		c->s_num++;
		if (c->s_num == 16)
			c->s_num = 5;
		if (SPRT_NIKOL)
			c->s_num = 17;
		c->s_speed = 0;
	}
}
