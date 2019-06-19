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
	printf("My debugging [%d]\n", debug(tbl, 1));
	while (sign)
	{
		in_out_to_zero(tbl);
		sign = 0;
		in_and_out(tbl); // Pay attention to this, try using tbl->q instead
		// for (int j=0;tbl->q[j];j++)
		// 	printf("room - [%s]-in-[%d]-out-[%d]\n", tbl->q[j]->name, tbl->q[j]->in, tbl->q[j]->out);
		sign = bad_in_outs(tbl, sign);
		c++;
		printf("======== COUNT [%d] ========\n", c);
		// count_pip(tbl, g_node);
		printf("Number of start paths = [%d] end = [%d]\n", tbl->start->out, tbl->end->in);
	}
	forming_queue(tbl);
	delete_input_forks(tbl);
	delete_output_forks(tbl);
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
			if (!ft_strcmp(node->branch->node->name, "Uhn0") || !ft_strcmp(node->branch->node->name, "Ymh6") || !ft_strcmp(node->branch->node->name, "Ymh6") ||
			!ft_strcmp(node->branch->node->name, "Vhr1") || !ft_strcmp(node->branch->node->name, "Tel3") || !ft_strcmp(node->branch->node->name, "Vqj7") ||
			!ft_strcmp(node->branch->node->name, "Gdk9") || !ft_strcmp(node->branch->node->name, "Set8") || !ft_strcmp(node->branch->node->name, "Auo9") ||
			!ft_strcmp(node->branch->node->name, "Nm_3") || !ft_strcmp(node->branch->node->name, "S_f1") || !ft_strcmp(node->branch->node->name, "Pfg8") ||
			!ft_strcmp(node->branch->node->name, "Stw5") || !ft_strcmp(node->branch->node->name, "Hfr1") || !ft_strcmp(node->branch->node->name, "Rhe3") ||
			!ft_strcmp(node->branch->node->name, "Mkr2") || !ft_strcmp(node->branch->node->name, "Wp_5") || !ft_strcmp(node->branch->node->name, "C_m9") ||
			!ft_strcmp(node->branch->node->name, "Gns8") || !ft_strcmp(node->branch->node->name, "Get3") || !ft_strcmp(node->branch->node->name, "Jpz8") ||
			!ft_strcmp(node->branch->node->name, "Yti2") || !ft_strcmp(node->branch->node->name, "Itx6") || !ft_strcmp(node->branch->node->name, "A_d4") ||
			!ft_strcmp(node->branch->node->name, "Jiu8") || !ft_strcmp(node->branch->node->name, "Phk1") || !ft_strcmp(node->branch->node->name, "Rw_8") ||
			!ft_strcmp(node->branch->node->name, "Gjx4") || !ft_strcmp(node->branch->node->name, "Rhz6") || !ft_strcmp(node->branch->node->name, "Kli2") ||
			!ft_strcmp(node->branch->node->name, "Tyy1") || !ft_strcmp(node->branch->node->name, "Ieg6") || !ft_strcmp(node->branch->node->name, "B_q2") ||
			!ft_strcmp(node->branch->node->name, "Bqx3") || !ft_strcmp(node->branch->node->name, "Ezw4"))
			{
				g_node = node->branch->node;
				// count_pip(tbl, g_node);
				printf("Deleting {%s}\n", node->branch->node->name);
			}
			
			sign = 1;
			node->branch = node->branch->next;
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
				pre_pip->next = pip->next;
			}
			else
				pre_pip = pip;
			pip = pip->next;
		}
	}
	return (sign);
}

int			debug(t_table *tbl, int a)
{
	t_pipe *pip;
	int 	i;

	i = 0;
	if (a)
		pip = tbl->start->branch;
	else
		pip = tbl->end->branch;
	while (pip)
	{
		i++;
		pip = pip->next;
	}
	return (i);
}