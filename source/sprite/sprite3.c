/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_create_sprt_list(t_cub *c, int i, int j)
{
	t_sprt	*node;

	if (!ft_strchr(SPRITES, c->map[i][j]))
		return ;
	node = ft_new_sprt_node(i, j);
	ft_fill_node(c, node);
	if (node->xpm_x_ratio < 0 || node->xpm_x_ratio > 1)
	{
		free(node);
		node = NULL;
		return ;
	}
	ft_add_sprt_node(&(c->sprt), node);
}
