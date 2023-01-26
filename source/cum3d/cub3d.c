/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_win_msg_background(t_cub *c)
{
	int	x;
	int	y;

	y = c->h_win / 2 - 15;
	while (++y < c->h_win / 2 + 5)
	{
		x = c->w_win / 2 - 5;
		while (++x < c->w_win / 2 + 170)
			my_mlx_pixel_put(c, x, y, 0x183E0C);
	}
}

void	ft_win_msg(t_cub *c)
{
	if (mouse.mouse_enable)
	{
		mlx_string_put(c->mlx, c->win, 20, 190, 0x00FF00, \
			"Mouse ON (right click to turn off)");
	}
	else
	{
		mlx_string_put(c->mlx, c->win, 20, 190, 0xFF0000, \
			"Mouse OFF (right click to turn on)");
	}
	if (way_length.forward <= DOOR_OPEN_MSG)
	{
		mlx_string_put(c->mlx, c->win, c->w_win / 2, c->h_win / 2, \
			0xFFFFFF, "Press <space> to open door!");
	}
}

int	ft_cub3d(t_cub *c)
{
	ft_draw_floor_and_ceilling(c);
	ft_draw_wall_by_map(c, 2);
	ft_win_msg(c);
	ft_set_ways_length(c);
	ft_mouse_move(c);
	mlx_do_sync(c->mlx);
	ft_reset_map(c);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	*c;

	if (ac != 2)
		ft_error("invalid num of argumnets\n", 1);
	c = (t_cub *)malloc(sizeof(t_cub));
	if (!c)
		ft_error("can't creat a t_cub struct\n", 1);
	ft_initiator(c, av);
	mlx_do_key_autorepeaton(c->mlx);
	mlx_hook(c->win, 2, 1L << 0, key_hook, c);
	mlx_hook(c->win, 6, 1L << 6, mouse_hook, c);
	mlx_hook(c->win, RED_CROSS, 0, ft_close, c);
	mlx_loop_hook(c->mlx, ft_cub3d, c);
	mlx_mouse_hook(c->win, mouse_click, c);
	mlx_loop(c->mlx);
	return (0);
}
