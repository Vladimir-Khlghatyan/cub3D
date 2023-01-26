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

t_sprt	*ft_new_sprt_node(int i, int j)
{
	t_sprt	*node;

	node = (t_sprt *)malloc(sizeof(t_sprt));
	if (!node)
	{
		printf("Can't create sprite list (malloc error)!");
		exit(1);
	}
	sprt_tmp.i = i;
	sprt_tmp.j = j;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_add_sprt_node(t_sprt **head, t_sprt *new)
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

void	ft_fill_sprt_tmp(double x, double y)
{
	sprt_tmp.x = x;
	sprt_tmp.y = y;
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
