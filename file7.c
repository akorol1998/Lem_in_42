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
	t_pipe	*pip;
	t_node	*node;
	int		sign;

	sign = 1;
	bad_links(tbl);
	directions(tbl);
	printf("My debugging [%d]\n", debug(tbl, 1));
	// while (sign)
	// {
		// in_out_to_zero(tbl);
		sign = 0;
		pip = tbl->start->branch;
		while (pip) // Pay attention to this, try using tbl->q instead
		{
			node = pip->node;
			in_and_out(tbl, node);
			pip = pip->next;
		}
		for (int j=0;tbl->q[j];j++)
			printf("room - [%s]-in-[%d]-out-[%d]\n", tbl->q[j]->name, tbl->q[j]->in, tbl->q[j]->out);

	// 	sign = bad_in_outs(tbl, sign);
	// }
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

// Deletinf dead ends
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