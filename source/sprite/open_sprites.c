/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_open_sprites1(t_cub *c)
{
	c->xpm[5].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC1, \
		&c->xpm[5].width, &c->xpm[5].height);
	c->xpm[5].addr = mlx_get_data_addr(c->xpm[5].ptr, &c->xpm[5].bpp, \
									&c->xpm[5].linelen, &c->xpm[5].endian);
	c->xpm[6].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC2, \
		&c->xpm[6].width, &c->xpm[6].height);
	c->xpm[6].addr = mlx_get_data_addr(c->xpm[6].ptr, &c->xpm[6].bpp, \
									&c->xpm[6].linelen, &c->xpm[6].endian);
	c->xpm[7].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC3, \
		&c->xpm[7].width, &c->xpm[7].height);
	c->xpm[7].addr = mlx_get_data_addr(c->xpm[7].ptr, &c->xpm[7].bpp, \
									&c->xpm[7].linelen, &c->xpm[7].endian);
	c->xpm[8].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC4, \
		&c->xpm[8].width, &c->xpm[8].height);
	c->xpm[8].addr = mlx_get_data_addr(c->xpm[8].ptr, &c->xpm[8].bpp, \
									&c->xpm[8].linelen, &c->xpm[8].endian);
	c->xpm[9].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC5, \
		&c->xpm[9].width, &c->xpm[9].height);
	c->xpm[9].addr = mlx_get_data_addr(c->xpm[9].ptr, &c->xpm[9].bpp, \
									&c->xpm[9].linelen, &c->xpm[9].endian);
	c->xpm[10].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC6, \
		&c->xpm[10].width, &c->xpm[10].height);
	c->xpm[10].addr = mlx_get_data_addr(c->xpm[10].ptr, &c->xpm[10].bpp, \
									&c->xpm[10].linelen, &c->xpm[10].endian);
}

static void	ft_open_sprites2(t_cub *c)
{
	c->xpm[11].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC7, \
		&c->xpm[11].width, &c->xpm[11].height);
	c->xpm[11].addr = mlx_get_data_addr(c->xpm[11].ptr, &c->xpm[11].bpp, \
									&c->xpm[11].linelen, &c->xpm[11].endian);
	c->xpm[12].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC8, \
		&c->xpm[12].width, &c->xpm[12].height);
	c->xpm[12].addr = mlx_get_data_addr(c->xpm[12].ptr, &c->xpm[12].bpp, \
									&c->xpm[12].linelen, &c->xpm[12].endian);
	c->xpm[13].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC9, \
		&c->xpm[13].width, &c->xpm[13].height);
	c->xpm[13].addr = mlx_get_data_addr(c->xpm[13].ptr, &c->xpm[13].bpp, \
									&c->xpm[13].linelen, &c->xpm[13].endian);
	c->xpm[14].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC10, \
		&c->xpm[14].width, &c->xpm[14].height);
	c->xpm[14].addr = mlx_get_data_addr(c->xpm[14].ptr, &c->xpm[14].bpp, \
									&c->xpm[14].linelen, &c->xpm[14].endian);
	c->xpm[15].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC11, \
		&c->xpm[15].width, &c->xpm[15].height);
	c->xpm[15].addr = mlx_get_data_addr(c->xpm[15].ptr, &c->xpm[15].bpp, \
									&c->xpm[15].linelen, &c->xpm[15].endian);
	c->xpm[16].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC12, \
		&c->xpm[16].width, &c->xpm[16].height);
	c->xpm[16].addr = mlx_get_data_addr(c->xpm[16].ptr, &c->xpm[16].bpp, \
									&c->xpm[16].linelen, &c->xpm[16].endian);
}

static void	ft_open_sprites3(t_cub *c)
{
	c->xpm[17].ptr = mlx_xpm_file_to_image(c->mlx, SPRT_PIC_NIKOL, \
		&c->xpm[17].width, &c->xpm[17].height);
	c->xpm[17].addr = mlx_get_data_addr(c->xpm[17].ptr, &c->xpm[17].bpp, \
									&c->xpm[17].linelen, &c->xpm[17].endian);
}

void	ft_open_sprites(t_cub *c)
{
	ft_open_sprites1(c);
	ft_open_sprites2(c);
	ft_open_sprites3(c);
}
