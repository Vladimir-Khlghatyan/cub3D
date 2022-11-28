/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	mouse_hook(int x, int y, t_cub *c)
{
	(void)y;
	if (x > mouse.old_x)
		ft_turn_around(c, KEY_RIGHT, MOUSE_RATIO);
	else if (x < mouse.old_x)
		ft_turn_around(c, KEY_LEFT, MOUSE_RATIO);
	mouse.old_x = x;
	return (0);
}

void	ft_mouse_move(t_cub *c)
{
	if (mouse.old_x > WIDTH_WINDOW - 4)
		ft_turn_around(c, KEY_RIGHT, MOUSE_SIDE_RATIO);
	if (mouse.old_x < 4)
		ft_turn_around(c, KEY_LEFT, MOUSE_SIDE_RATIO);
}
