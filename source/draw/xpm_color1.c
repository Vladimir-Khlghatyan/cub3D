/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_color1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_xpm_color_no(t_cub *c, int start, int end, int win_y)
{
	int	x;
	int	y;
	int	color;
	int	n;

	n = 0;
	if (c->w_or_d == 2)
		n = 4;
	x = (int)c->cross_coor_x % SIZE;
	x = (x * c->xpm[n].width) / SIZE;
	if (end - start <= HEIGHT_WINDOW)
		y = c->xpm[n].height * (win_y - start) / (end - start);
	else
	{
		y = (c->xpm[n].height * (end - start) - \
			c->xpm[n].height * HEIGHT_WINDOW) / (2 * (end - start));
		y = y + (win_y * (c->xpm[n].height - 2 * y)) / HEIGHT_WINDOW;
	}
	color = ft_get_xmp_pixel_color(c->xpm[n], x, y);
	return (color);
}

int	ft_xpm_color_so(t_cub *c, int start, int end, int win_y)
{
	int	x;
	int	y;
	int	color;
	int	n;

	n = 1;
	if (c->w_or_d == 2)
		n = 4;
	x = SIZE - (int)c->cross_coor_x % SIZE;
	x = (x * c->xpm[n].width) / SIZE;
	if (end - start <= HEIGHT_WINDOW)
		y = c->xpm[n].height * (win_y - start) / (end - start);
	else
	{
		y = (c->xpm[n].height * (end - start) - \
			c->xpm[n].height * HEIGHT_WINDOW) / (2 * (end - start));
		y = y + (win_y * (c->xpm[n].height - 2 * y)) / HEIGHT_WINDOW;
	}
	color = ft_get_xmp_pixel_color(c->xpm[n], x, y);
	return (color);
}

int	ft_xpm_color_we(t_cub *c, int start, int end, int win_y)
{
	int	x;
	int	y;
	int	color;
	int	n;

	n = 2;
	if (c->w_or_d == 2)
		n = 4;
	x = SIZE - (int)c->cross_coor_y % SIZE;
	x = (x * c->xpm[n].width) / SIZE;
	if (end - start <= HEIGHT_WINDOW)
		y = c->xpm[n].height * (win_y - start) / (end - start);
	else
	{
		y = (c->xpm[n].height * (end - start) - \
			c->xpm[n].height * HEIGHT_WINDOW) / (2 * (end - start));
		y = y + (win_y * (c->xpm[n].height - 2 * y)) / HEIGHT_WINDOW;
	}
	color = ft_get_xmp_pixel_color(c->xpm[n], x, y);
	return (color);
}

int	ft_xpm_color_ea(t_cub *c, int start, int end, int win_y)
{
	int	x;
	int	y;
	int	color;
	int	n;

	n = 3;
	if (c->w_or_d == 2)
		n = 4;
	x = (int)c->cross_coor_y % SIZE;
	x = (x * c->xpm[n].width) / SIZE;
	if (end - start <= HEIGHT_WINDOW)
		y = c->xpm[n].height * (win_y - start) / (end - start);
	else
	{
		y = (c->xpm[n].height * (end - start) - \
			c->xpm[n].height * HEIGHT_WINDOW) / (2 * (end - start));
		y = y + (win_y * (c->xpm[n].height - 2 * y)) / HEIGHT_WINDOW;
	}
	color = ft_get_xmp_pixel_color(c->xpm[n], x, y);
	return (color);
}
