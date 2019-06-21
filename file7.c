/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:43:23 by akorol            #+#    #+#             */
/*   Updated: 2019/06/15 16:43:34 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		data_tunage(t_table *tbl)
{
	// t_pipe	*pip;
	// t_node	*node;
	int		c;
	int		sign;

	sign = 1;
	c = 0;
	bad_links(tbl);
	directions(tbl);
	printf("My debugging\n");
	while (sign)
	{
		in_out_to_zero(tbl);
		sign = 0;
		in_and_out(tbl);
		sign = bad_in_outs(tbl, sign);
		c++;
	}
	printf("The start out [%d]\n", tbl->start->out);
	forming_queue(tbl);
	delete_input_forks(tbl);
	// sign = 1;
	// c = 0;
	// while (sign)
	// {
	// 	in_out_to_zero(tbl);
	// 	sign = 0;
	// 	in_and_out(tbl);
	// 	sign = bad_in_outs(tbl, sign);
	// 	c++;
	// }
	delete_output_forks(tbl);
	// sign = 1;
	// c = 0;
	// while (sign)
	// {
	// 	in_out_to_zero(tbl);
	// 	sign = 0;
	// 	in_and_out(tbl);
	// 	sign = bad_in_outs(tbl, sign);
	// 	c++;
	// }
}

void		in_out_to_zero(t_table *tbl)
{
	// t_node	*node;
	// t_pipe	*pip;
	int		i;

	i = -1;
	while (tbl->q[++i])
	{
		tbl->q[i]->out = 0;
		tbl->q[i]->in = 0;
	}
}

// Deleting dead ends
int			bad_in_outs(t_table *tbl, int sign)
{
	t_pipe	*pip;
	t_pipe	*del;
	t_node	*node;
	t_pipe	*pre_pip;
	int		i;

	i = -1;
	while (tbl->q[++i])
	{
		node = tbl->q[i];
		
		
		while (node->branch && (!node->branch->node->out ||
		!node->branch->node->in) &&
		ft_strcmp(node->branch->node->name, tbl->end->name) && 
		ft_strcmp(node->branch->node->name, tbl->start->name))
		{
			if (!ft_strcmp(node->branch->node->name, "K_d2") || !ft_strcmp(node->branch->node->name, "Tdz2") || !ft_strcmp(node->branch->node->name, "Dio3") ||
			!ft_strcmp(node->branch->node->name, "Jmy2") || !ft_strcmp(node->branch->node->name, "Pci3") || !ft_strcmp(node->branch->node->name, "Pmw2") ||
			!ft_strcmp(node->branch->node->name, "Gxx1") || !ft_strcmp(node->branch->node->name, "Kqa2") || !ft_strcmp(node->branch->node->name, "Jgc5") ||
			!ft_strcmp(node->branch->node->name, "Ycp6") || !ft_strcmp(node->branch->node->name, "Hnk6") || !ft_strcmp(node->branch->node->name, "Jrp4") ||
			!ft_strcmp(node->branch->node->name, "Rao6") || !ft_strcmp(node->branch->node->name, "Uhr4") || !ft_strcmp(node->branch->node->name, "Zzf2") ||//
			!ft_strcmp(node->branch->node->name, "Rw_2") || !ft_strcmp(node->branch->node->name, "Vpe9") || !ft_strcmp(node->branch->node->name, "Baj8") ||
			!ft_strcmp(node->branch->node->name, "E_w8") || !ft_strcmp(node->branch->node->name, "Ecx4") || !ft_strcmp(node->branch->node->name, "Gae2") ||
			!ft_strcmp(node->branch->node->name, "Seh9") || !ft_strcmp(node->branch->node->name, "Tw_0") || !ft_strcmp(node->branch->node->name, "Rsc2") ||
			!ft_strcmp(node->branch->node->name, "Gbm4") || !ft_strcmp(node->branch->node->name, "Zkb7") || !ft_strcmp(node->branch->node->name, "Zfe8") ||
			!ft_strcmp(node->branch->node->name, "Yhr2") || !ft_strcmp(node->branch->node->name, "Dkf2") || !ft_strcmp(node->branch->node->name, "Jma2") ||
			!ft_strcmp(node->branch->node->name, "S_x0") || !ft_strcmp(node->branch->node->name, "Jjo2") || !ft_strcmp(node->branch->node->name, "Dii9") ||
			!ft_strcmp(node->branch->node->name, "Oo_2") || !ft_strcmp(node->branch->node->name, "Irl9"))
			{
				g_node = node->branch->node;
				// count_pip(tbl, g_node);
				printf("Deleting {%s}\n", node->branch->node->name);
			}
			
			sign = 1;
			del = node->branch;
			node->branch = node->branch->next;
			free(del);
		}
		pip = node->branch;
		while (pip)
		{
			if ((!pip->node->out || !pip->node->in) &&
			ft_strcmp(pip->node->name, tbl->end->name) &&
			ft_strcmp(pip->node->name, tbl->start->name))
			{
				sign = 1;
				// printf("Deleting {%s}\n", pip->node->name);
				del = pre_pip->next;
				pre_pip->next = pip->next;
				free(del);
			}
			else
				pre_pip = pip;
			pip = pip->next;
		}
	}
	return (sign);
}