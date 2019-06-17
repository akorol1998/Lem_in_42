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
	int		flag;

	idx = 0;
	tbl->q[idx] = cur;
	flag = 0;
	while (cur) // && ft_strcmp(cur->name, tbl->end->name)
	{
		add_to_queue(tbl, cur);
		cur = tbl->q[++idx];
		if (cur && !ft_strcmp(cur->name, tbl->end->name))
			flag = 1;
	}
	// if (cur && !ft_strcmp(cur->name, tbl->end->name))
	tbl->end->level = INT_MAX;
	// for (int j=0;tbl->q[j];j++)
		// printf("room - [%s]-level-[%d]\n", tbl->q[j]->name, tbl->q[j]->level);
	if (!flag)
		return (-1);
	return (idx);
}

// Setting up directions for the nodes
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

// Deleting same levele links and levele = -1
void		bad_links(t_table *tbl)
{
	t_pipe	*pip;
	t_node	*node;
	t_pipe	*pre_pip;

	node = tbl->start;
	while (node)
	{
		while ((node->branch && node->branch->node->level == node->level) || (node->branch && node->branch->node->level == -1))
		{
			if (!ft_strcmp(node->name, tbl->end->name))
			{
				printf("Level [%d]-name-[%s]\n", node->branch->node->level, node->branch->node->name);
				printf("End level [%d]-name-[%s]\n", node->level, node->name);
			}
			node->branch = node->branch->next;
		}
		pip = node->branch;
		while (pip)
		{
			
			if (pip->node->level == node->level || pip->node->level == -1)
			{
				if (!ft_strcmp(node->name, tbl->end->name))
				{
					printf("Level [%d]-name-[%s]\n", pip->node->level, pip->node->name);
					printf("End level [%d]-name-[%s]\n", node->level, node->name);
				}
				pre_pip->next = pip->next;
			}
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
			if (!ft_strcmp(tbl->end->name, node->name))
				printf("TUTTTTAAAAAAAAAAA\n");
			node->out++;
			in_and_out(tbl, pip->node);
			pip = pip->next;
		}
	}
}