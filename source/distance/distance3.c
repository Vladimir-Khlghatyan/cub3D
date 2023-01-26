/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ft_correct_radian(double radian)
{
	if (radian >= 2 * M_PI)
	{
		while (radian >= 2 * M_PI)
			radian -= (2 * M_PI);
		return (radian);
	}
	if (radian < 0)
	{
		while (radian < 0)
			radian += (2 * M_PI);
		return (radian);
	}
	return (radian);
}

double	ft_ray_sharp_radian(double radian)
{
	radian = ft_correct_radian(radian);
	if (radian <= M_PI_2)
		return (radian);
	if (radian > M_PI_2 && radian <= M_PI)
		return (M_PI - radian);
	if (radian > M_PI && radian <= M_PI + M_PI_2)
		return (radian - M_PI);
	if (radian > M_PI + M_PI_2)
		return (2 * M_PI - radian);
	return (0);
}
