/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_sprt	*ft_new_sprt_node(t_cub *c, int i, int j)
{
	t_sprt	*node;

	node = (t_sprt *)malloc(sizeof(t_sprt));
	if (!node)
		ft_error(c, "not enough resources. Try again!\n", 1);
	node->map_i = i;
	node->map_j = j;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

// 	double	ccx0; // (circle center X) - (pl_board_x)
// 	double	ccy0; // (circle center Y) - (pl_board_y)

static void	ft_fill_node(t_cub *c, t_sprt *node)
{
	double	ccx0;
	double	ccy0;

	if (node == NULL)
		return ;
	node->rds = SIZE / 2;
	ccx0 = node->map_j * SIZE + SIZE / 2 - c->pl_board_x;
	ccy0 = node->map_i * SIZE + SIZE / 2 - c->pl_board_y;
	node->rr = ft_correct_radian(c->cntr_rad + c->fov / 2 - c->step);
	node->cr = ft_correct_radian(c->cntr_rad);
	node->ix = ft_i_unit_vec_transformation(node->cr, 'x');
	node->iy = ft_i_unit_vec_transformation(node->cr, 'y');
	node->jx = ft_j_unit_vec_transformation(node->cr, 'x');
	node->jy = ft_j_unit_vec_transformation(node->cr, 'y');
	node->ccx0_tr = ccx0 * node->ix + ccy0 * node->jx;
	node->ccy0_tr = ccx0 * node->iy + ccy0 * node->jy;
	node->sdp = fabs(node->ccy0_tr);
	node->s_x0_tr = node->sdp * tan(fabs(c->fov / 2 - c->step));
	if (ft_is_1st_grater_than_2nd(node->rr, node->cr))
		node->s_x0_tr *= -1;
	node->xpm_x_ratio = 1 - (node->rds + node->ccx0_tr - node->s_x0_tr) / \
						(2 * node->rds);
	node->sprt_char = c->map[node->map_i][node->map_j];
}

static void	ft_add_sprt_node(t_sprt **head, t_sprt *new)
{
	t_sprt	*last_node;

	if (new == NULL)
		return ;
	if (!*head)
		*head = new;
	else
	{
		last_node = *head;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
		new->prev = last_node;
	}
}

void	ft_create_sprt_list(t_cub *c, int i, int j)
{
	t_sprt	*node;

	if (!ft_strchr(SPRITES, c->map[i][j]))
		return ;
	node = ft_new_sprt_node(c, i, j);
	ft_fill_node(c, node);
	if (node->xpm_x_ratio < 0 || node->xpm_x_ratio > 1)
	{
		free(node);
		node = NULL;
		return ;
	}
	if (c->start == -1)
		c->start = c->i;
	c->end = c->i + 1;
	ft_add_sprt_node(&(c->sprt), node);
}

void	ft_free_sprt_list(t_cub *c)
{
	t_sprt	*tmp;
	t_sprt	*tmp2;

	if (c->sprt == NULL)
		return ;
	tmp = c->sprt;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	c->sprt = NULL;
}
