/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_initiator1(t_cub *c, char **argv)
{
	ft_map_name_check(c, argv[1]);
	c->mlx = mlx_init();
	if (!c->mlx)
	{
		write(2, RED, ft_strlen(RED));
		write(2, "MLX was not initialized!\n", 25);
		write(2, "https://harm-smits.github.io/42docs/", 36);
		write(2, "libs/minilibx/getting_started.html\n", 35);
		write(2, RESET, ft_strlen(RESET));
		ft_error(c, NULL, 1);
	}
	c->init_map = ft_get_map(argv[1], c);
	c->map = ft_copy_map(c, c->init_map);
	c->w_win = WIDTH_WINDOW;
	c->h_win = HEIGHT_WINDOW;
	c->win = mlx_new_window(c->mlx, c->w_win, c->h_win, "Cub3D");
	if (!c->win)
		ft_error(c, "can't open new window! Try again!\n", 1);
	c->img = mlx_new_image(c->mlx, c->w_win, c->h_win);
	c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->line_length, &c->endian);
	ft_draw_floor_and_ceilling(c);
	mlx_put_image_to_window(c->mlx, c->win, c->img, 0, 0);
	c->fov = FOV;
	c->w_map = ft_strlen(c->map[0]);
	c->h_map = ft_arrlen(c->map);
}

static void	ft_initiator2_util(t_cub *c, int x, int y, int flag)
{
	minimap.pl_x = -1;
	minimap.pl_y = -1;
	c->door_is_open = 0;
	mouse.mouse_enable = 0;
	if (flag == 1)
	{
		c->dir_vec_x = x / 1.0;
		c->dir_vec_y = y / 1.0;
	}
	else if (flag == 2)
	{
		c->pl_map_x = x;
		c->pl_map_y = y;
	}
}

static void	ft_initiator2(t_cub *c)
{
	int	i;
	int	j;

	i = -1;
	while (c->map[++i])
	{
		j = -1;
		while (c->map[i][++j])
		{
			if (c->map[i][j] == 'N')
				ft_initiator2_util(c, 0, -1, 1);
			else if (c->map[i][j] == 'S')
				ft_initiator2_util(c, 0, 1, 1);
			else if (c->map[i][j] == 'E')
				ft_initiator2_util(c, 1, 0, 1);
			else if (c->map[i][j] == 'W')
				ft_initiator2_util(c, -1, 0, 1);
			if (c->map[i][j] == 'N' || c->map[i][j] == 'S' || \
				c->map[i][j] == 'E' || c->map[i][j] == 'W')
				ft_initiator2_util(c, j, i, 2);
		}
	}
	c->pl_board_x = c->pl_map_x * SIZE + SIZE / 2;
	c->pl_board_y = c->pl_map_y * SIZE + SIZE / 2;
}

static void	ft_initiator3(t_cub *c)
{
	int	i;

	c->xpm = (t_xpm *)malloc(sizeof(t_xpm) * XPM_COUNT);
	if (!c->xpm)
		ft_error(c, "something went wrong with malloc, try again!\n", 1);
	c->xpm[0].ptr = c->xpm_no;
	c->xpm[1].ptr = c->xpm_so;
	c->xpm[2].ptr = c->xpm_we;
	c->xpm[3].ptr = c->xpm_ea;
	i = -1;
	while (++i < 4)
	{
		c->xpm[i].width = c->wxpm[i];
		c->xpm[i].height = c->hxpm[i];
		c->xpm[i].addr = mlx_get_data_addr(c->xpm[i].ptr, &c->xpm[i].bpp, \
									&c->xpm[i].linelen, &c->xpm[i].endian);
	}
}

void	ft_initiator(t_cub *c, char **argv)
{
	ft_initiator1(c, argv);
	ft_initiator2(c);
	ft_initiator3(c);
	ft_open_sprites(c);
	c->s_num = 4;
	c->s_speed = 0;
}
