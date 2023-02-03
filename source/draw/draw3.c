/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_set_ways_length(t_cub *c)
{
	way_length.forward_for_door = ft_ray_cast(c, c->fov / 2, 1, -1);
	way_length.forward = ft_ray_cast(c, c->fov / 2, 2, -1);
	way_length.f_radian = ft_correct_radian(c->cntr_rad + 0);
	way_length.back = ft_ray_cast(c, c->fov / 2 + M_PI, 2, -1);
	way_length.b_radian = ft_correct_radian(c->cntr_rad + M_PI);
	way_length.left = ft_ray_cast(c, c->fov / 2 + M_PI + M_PI_2, 2, -1);
	way_length.l_radian = ft_correct_radian(c->cntr_rad + M_PI_2);
	way_length.right = ft_ray_cast(c, c->fov / 2 + M_PI_2, 2, -1);
	way_length.r_radian = ft_correct_radian(c->cntr_rad - M_PI_2);
}
