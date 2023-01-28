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

static void	ft_set_n_and_x(t_cub *c, int *n, int *x)
{
	if (c->pic == 'N')
		(*n) = 0;
	else if (c->pic == 'S')
		(*n) = 1;
	else if (c->pic == 'W')
		(*n) = 2;
	else
		(*n) = 3;
	if (c->w_or_d == 2)
		(*n) += 17;
	if (c->pic == 'N')
		(*x) = ((int)c->cross_coor_x % SIZE * c->xpm[*n].width) / SIZE;
	else if (c->pic == 'S')
		(*x) = ((SIZE - (int)c->cross_coor_x % SIZE) * c->xpm[*n].width) / SIZE;
	else if (c->pic == 'W')
		(*x) = ((SIZE - (int)c->cross_coor_y % SIZE) * c->xpm[*n].width) / SIZE;
	else
		(*x) = ((int)c->cross_coor_y % SIZE * c->xpm[*n].width) / SIZE;
}

int	ft_xpm_color_wall(t_cub *c, int start, int end, int win_y)
{
	int	x;
	int	y;
	int	color;
	int	n;

	ft_set_n_and_x(c, &n, &x);
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
