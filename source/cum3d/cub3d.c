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

t_cub	*ft_cub_malloc(void)
{
	t_cub	*c;

	c = (t_cub *)malloc(sizeof(t_cub));
	if (!c)
		ft_error(c, "can't creat a t_cub struct\n", 1);
	c->mlx = NULL;
	c->win = NULL;
	c->img = NULL;
	c->addr = NULL;
	c->init_map = NULL;
	c->map = NULL;
	c->xpm = NULL;
	c->sprt = NULL;
	c->sprt_tmp = NULL;
	return (c);
}

void	ft_win_msg(t_cub *c)
{
	int	pos_x;
	int	pos_y;

	pos_x = c->h_win / (MINIMAP_RATIO * 10);
	pos_y = c->h_win / (MINIMAP_RATIO * 10) + c->h_win / MINIMAP_RATIO + 10;
	if (mouse.mouse_enable)
	{
		mlx_string_put(c->mlx, c->win, pos_x, pos_y, 0x00FF00, \
			"Mouse ON (right click to turn off)");
	}
	else
	{
		mlx_string_put(c->mlx, c->win, pos_x, pos_y, 0xFF0000, \
			"Mouse OFF (right click to turn on)");
	}
	if (way_length.forward <= DOOR_OPEN_MSG)
	{
		mlx_string_put(c->mlx, c->win, c->w_win / 2, c->h_win / 2, \
			0xFFFFFF, "Go to the door and press <space> to open it!");
	}
}

int	ft_cub3d(t_cub *c)
{
	ft_draw_wall_by_map(c, 2, 0, 0);
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
		ft_error(NULL, "invalid num of argumnets\n", 1);
	c = ft_cub_malloc();
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
