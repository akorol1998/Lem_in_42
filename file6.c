/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:43:31 by akorol            #+#    #+#             */
/*   Updated: 2019/06/15 11:43:43 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			setting_levels(t_table *tbl, t_node *cur)
{
	int		idx;

	idx = 0;
	tbl->q[idx] = cur;
	while (cur && ft_strcmp(cur->name, tbl->end->name))
	{
		add_to_queue(tbl, cur);
		cur = tbl->q[++idx];
	}
	if (cur && !ft_strcmp(cur->name, tbl->end->name))
			cur->level = INT_MAX;
	if (!tbl->q[idx])
		return (-1);
	return (idx);
}

void		set_direction(t_pipe *branch, t_node *prev)
{
	t_pipe	*pip;
	t_node	*node;
	t_pipe	*pre_pip;

	node = branch->node;
	while ((node->branch && (!ft_strcmp(node->branch->node->name, prev->name) &&
	prev->level < node->level)) || (node->level == -1))
		node->branch = node->branch->next;
	pip = node->branch;
	while (pip)
	{
		if ((!ft_strcmp(pip->node->name, prev->name) &&
		prev->level < node->level) || (pip->node->level == -1))
			pre_pip->next = pip->next;
		else
			pre_pip = pip;
		pip = pip->next;
	}
}

void		directions(t_table *tbl)
{
	int		i;
t_pipe	*pip;

	i = -1;
	while (tbl->q[++i])
	{
		pip = tbl->q[i]->branch;
		while (pip)
		{
			set_direction(pip, tbl->q[i]);
			pip = pip->next;
		}
	}
}

void		bad_links(t_table *tbl)
{
	t_pipe	*pip;
	t_node	*node;
	t_pipe	*pre_pip;

	node = tbl->start;
	while (node)
	{
		ft_putstr("seg ");
		while ((node->branch && node->branch->node->level == node->level) || (node->branch && node->branch->node->level == -1))
			node->branch = node->branch->next;
		ft_putstr("fault\n");
		pip = node->branch;
		while (pip)
		{
			if (pip->node->level == node->level || pip->node->level == -1)
				pre_pip->next = pip->next;
			else
				pre_pip = pip;
			pip = pip->next;
		}
		node = node->link;
	}
}

void		in_and_out(t_table *tbl, t_node *node)
{
	t_pipe	*pip;

	pip = node->branch;
	if (ft_strcmp(node->name, tbl->start->name))
		node->in++;
	if (!node->out)
	{
		while (pip)
		{
			node->out++;
			in_and_out(tbl, pip->node);
			pip = pip->next;
		}
	}
}