/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_is_1st_grater_than_2nd(double angle1, double angle2)
{
	if (angle1 == 0 && angle2 < M_PI_2)
		return (0);
	if (angle1 == 0 && angle2 > M_PI + M_PI_2)
		return (1);
	if (angle2 == 0 && angle1 < M_PI_2)
		return (1);
	if (angle2 == 0 && angle1 > M_PI + M_PI_2)
		return (0);
	if (angle2 > M_PI + M_PI_2 && angle1 < M_PI_2)
		return (1);
	if (angle2 < M_PI_2 && angle1 > M_PI + M_PI_2)
		return (0);
	if (angle1 > angle2)
		return (1);
	return (0);
}

double	ft_i_unit_vec_transformation(double radian, char flag)
{
	while (radian > 2 * M_PI)
		radian -= 2 * M_PI;
	if (radian <= M_PI_2 && flag == 'x')
		return (cos(M_PI_2 - radian));
	if (radian <= M_PI && flag == 'x')
		return (cos(radian - M_PI_2));
	if (radian <= M_PI + M_PI_2 && flag == 'x')
		return (-sin(radian - M_PI));
	if (radian > M_PI + M_PI_2 && flag == 'x')
		return (-cos(radian - M_PI - M_PI_2));
	if (radian <= M_PI_2 && flag == 'y')
		return (-sin(M_PI_2 - radian));
	if (radian <= M_PI && flag == 'y')
		return (sin(radian - M_PI_2));
	if (radian <= M_PI + M_PI_2 && flag == 'y')
		return (cos(radian - M_PI));
	if (radian > M_PI + M_PI_2 && flag == 'y')
		return (-sin(radian - M_PI - M_PI_2));
	return (-1);
}

double	ft_j_unit_vec_transformation(double radian, char flag)
{
	while (radian > 2 * M_PI)
		radian -= 2 * M_PI;
	if (radian <= M_PI_2 && flag == 'x')
		return (cos(radian));
	if (radian <= M_PI && flag == 'x')
		return (-sin(radian - M_PI_2));
	if (radian <= M_PI + M_PI_2 && flag == 'x')
		return (-cos(radian - M_PI));
	if (radian > M_PI + M_PI_2 && flag == 'x')
		return (sin(radian - M_PI - M_PI_2));
	if (radian <= M_PI_2 && flag == 'y')
		return (sin(radian));
	if (radian <= M_PI && flag == 'y')
		return (cos(radian - M_PI_2));
	if (radian <= M_PI + M_PI_2 && flag == 'y')
		return (-sin(radian - M_PI));
	if (radian > M_PI + M_PI_2 && flag == 'y')
		return (-cos(radian - M_PI - M_PI_2));
	return (-1);
}
