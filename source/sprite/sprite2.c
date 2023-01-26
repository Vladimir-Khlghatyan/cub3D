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

void	ft_fill_node1(t_cub *c, t_sprt *node)
{
	node->rds = SIZE / 2;
	node->pbx = c->pl_board_x;
	node->pby = c->pl_board_y;
	node->ccx = sprt_tmp.j * SIZE + SIZE / 2;
	node->ccy = sprt_tmp.i * SIZE + SIZE / 2;
	node->ccx0 = node->ccx - node->pbx;
	node->ccy0 = node->ccy - node->pby;
	node->cx = sprt_tmp.x;
	node->cy = sprt_tmp.y;
	node->rr = ft_correct_radian(c->cntr_rad + c->fov / 2 - sprt_tmp.step);
	node->cr = ft_correct_radian(c->cntr_rad);
	node->crt = 2 * M_PI - node->cr;
	if (node->cr <= M_PI_2)
		node->crt = M_PI_2 - node->cr;
	else if (node->cr > M_PI_2 && node->cr <= M_PI)
		node->crt = node->cr - M_PI_2;
	else if (node->cr > M_PI && node->cr <= M_PI + M_PI_2)
		node->crt = node->cr - M_PI;
}

void	ft_fill_node2(t_cub *c, t_sprt *node)
{
	(void)*c;
	node->iytr = 1;
	if ((node->cr <= M_PI_2) || (node->cr > M_PI + M_PI_2))
		node->iytr = -1;
	node->jytr = 1;
	if (node->cr > M_PI)
		node->jytr = -1;
	node->iyt = node->iytr * cos(node->crt);
	if (node->cr <= M_PI)
		node->iyt = node->iytr * sin(node->crt);
	node->jyt = node->jytr * sin(node->crt);
	if (node->cr <= M_PI)
		node->jyt = node->jytr * cos(node->crt);
	node->sdp = fabs(node->ccx0 * node->iyt + node->ccy0 * node->jyt);
	if (ft_is_1st_grater_than_2nd(node->rr, node->cr))
		node->rpfcr = 'l';
	else
		node->rpfcr = 'r';
	node->pdfc = ft_distance(node->pbx, node->pby, node->cx, node->cy);
	node->pdfcc = ft_distance(node->pbx, node->pby, node->ccx, node->ccy);
	node->ccdfc = ft_distance(node->ccx, node->ccy, node->cx, node->cy);
	node->angl_spo = ft_cosine_angle(node->pdfc, node->pdfcc, node->ccdfc);
	node->angl_hpo = acos(node->sdp / node->pdfcc);
}

void	ft_fill_node3(t_cub *c, t_sprt *node)
{
	(void)*c;
	node->angl_sph = fabs(node->rr - node->cr);
	if (node->cr < M_PI_2 && node->rr > M_PI + M_PI_2)
		node->angl_sph = 2 * M_PI + node->cr - node->rr;
	else if (node->rr < M_PI_2 && node->cr > M_PI + M_PI_2)
		node->angl_sph = 2 * M_PI - node->cr + node->rr;
	node->l_ho = node->sdp * tan(node->angl_hpo);
	node->l_hs = node->sdp * tan(node->angl_sph);
	node->l_ps = node->sdp / cos(node->angl_sph);
	node->l_so = ft_cosine_length(node->l_ps, node->pdfcc, node->angl_spo);
	node->area_sph = (node->sdp * node->l_hs) / 2;
	node->area_oph = (node->sdp * node->l_ho) / 2;
	node->area_spo = ft_heron_forumla(node->pdfcc, node->l_ps, node->l_so);
	node->s_pos = 'o';
	if (fabs(node->area_oph - node->area_sph - node->area_spo) < 0.000001 && \
		node->area_sph != 0)
		node->s_pos = 'i';
	node->l_se = node->rds + node->l_so;
	if ((node->rpfcr == 'l' && node->s_pos == 'i') || \
		(node->rpfcr == 'r' && node->s_pos == 'o'))
		node->l_se = node->rds - node->l_so;
}

void	ft_fill_node4(t_cub *c, t_sprt *node)
{
	(void)*c;
	node->angl_po_vec = ft_abgle_of_vector(node->ccx0, node->ccy0);
	if (ft_is_1st_grater_than_2nd(node->angl_po_vec, node->cr))
		node->po_vec_pos = 'l';
	else
		node->po_vec_pos = 'r';
	if (node->area_sph < 0.0001 && node->po_vec_pos == 'r')
		node->xpm_x_ratio = 1 - (node->rds + node->l_so) / (2 * node->rds);
	else if (node->area_sph < 0.0001 && node->po_vec_pos == 'l')
		node->xpm_x_ratio = 1 - (node->rds - node->l_so) / (2 * node->rds);
	else
		node->xpm_x_ratio = 1 - node->l_se / (2 * node->rds);
}

void	ft_fill_node(t_cub *c, t_sprt *node)
{
	if (node == NULL)
		return ;
	ft_fill_node1(c, node);
	ft_fill_node2(c, node);
	ft_fill_node3(c, node);
	ft_fill_node4(c, node);
}
