/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ft_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

double	ft_heron_forumla(double a, double b, double c)
{
	double	p;

	p = (a + b + c) / 2;
	return (sqrt(p * (p - a) * (p - b) * (p - c)));
}

double	ft_cosine_length(double a, double b, double angle)
{
	return (sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(angle)));
}

double	ft_cosine_angle(double a, double b, double c)
{
	return (acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)));
}
