/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ft_abgle_of_vector(double x, double y)
{
	if (x >= 0 && y <= 0)
		return (atan(fabs(y / x)));
	if (x <= 0 && y <= 0)
		return (M_PI - atan(fabs(y / x)));
	if (x <= 0 && y >= 0)
		return (M_PI + atan(fabs(y / x)));
	if (x >= 0 && y >= 0)
		return (2 * M_PI - atan(fabs(y / x)));
	return (-1);
}

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
