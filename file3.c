/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:10:11 by akorol            #+#    #+#             */
/*   Updated: 2019/06/06 11:10:23 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


int			launch_algorithm(t_table *tbl)
{
	t_node	*curr;

	curr = tbl->nodes;
	set_levels(tbl);
	return (1);
}

void		add_to_queue(t_table *tbl, t_node *node)
{
	t_pipe	*pip;
	int		i;
	int		flag;
	int		idx;

	idx = -1;
	pip = node->branch;
	while (tbl->q[++idx])
		;
	while (pip)
	{
		i = -1;
		flag = 1;
		while (tbl->q[++i])
		{
			if (!ft_strcmp(tbl->q[i]->name, pip->node->name))
				flag = 0;
		}
		if (flag)
		{
			tbl->q[idx] = pip->node;
			pip->node->prev = node;
			idx++;
		}
		pip = pip->next;
	}
}

int			set_levels(t_table *tbl)
{
	t_node	*cur;
	int		idx;

	idx = 0;
	cur = tbl->nodes;
	tbl->q[idx] = cur;
	while (cur && ft_strcmp(cur->name, tbl->end->name))
	{
		add_to_queue(tbl, cur);
		cur = tbl->q[++idx];
		ft_putstr("Room = ");
		if (cur)
			ft_putstr("exists = ");
		else
			ft_putstr(" not = ");
		ft_putstr(cur->name);
		ft_putstr("\n");
	}
	ft_putstr("here is a node ");
	ft_putstr(cur->name);
	ft_putstr("\n");
	ft_putstr("here is end name");
	ft_putstr(tbl->end->name);
	ft_putstr("\n");
	return (1);
}

void		through_net(t_node *nodder, t_table *tbl, int w, t_node *tail)
{
	t_pipe	*pip;
	t_node	*node;

	printf("hi there\n");
	if (nodder->branch && ft_strcmp(nodder->name, tbl->start->name))
	{
		printf("Not start\n");
		pip = nodder->branch;
		while (pip)
		{
			node = pip->node;
			if (!node->visited)
			{
				printf("---===---\n");
				node->weight = w + 1;
				node->visited = 1;
				printf("END %d", tail->weight);
				through_net(node, tbl, w + 1, tail);
			}
			pip = pip->next;
		}
	}
}
