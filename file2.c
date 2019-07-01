/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:35:20 by akorol            #+#    #+#             */
/*   Updated: 2019/06/05 12:35:31 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			linking(char **data, t_table *tbl)
{
	t_pipe	*pip;
	t_node	*node;
	t_node	*node2;

	pip = NULL;
	node = tbl->nodes;
	node2 = tbl->nodes;
	if (!ft_strcmp(data[0], data[1]))
		return (1);
	while (node && ft_strcmp(node->name, data[0]))
	{
		node = node->link;
	}
	while (node2 && ft_strcmp(node2->name, data[1]))
		node2 = node2->link;
	if (node && node2 && connecting_nodes(node, node2))
		return (1);
	else
		return (0);
}

int			connecting_nodes(t_node *node, t_node *node2)
{
	t_pipe	*pip;

	if (!node->branch)
	{
		node->branch = (t_pipe*)malloc(sizeof(t_pipe));
		node->branch->node = node2;
		node->branch->next = NULL;
	}
	else
	{
		pip = node->branch;
		while (pip->next)
		{
			if (!ft_strcmp(pip->node->name, node2->name))
				return (0);
			pip = pip->next;
		}
		pip->next = (t_pipe *)malloc(sizeof(t_pipe));
		pip = pip->next;
		pip->node = node2;
		pip->next = NULL;
	}
	connect_node2(node2, node);
	return (1);
}

int			connect_node2(t_node *node2, t_node *node)
{
	t_pipe	*pip;

	if (!node2->branch)
	{
		node2->branch = (t_pipe*)malloc(sizeof(t_pipe));
		node2->branch->node = node;
		node2->branch->next = NULL;
	}
	else
	{
		pip = node2->branch;
		while (pip->next)
		{
			if (!ft_strcmp(pip->node->name, node->name))
				return (0);
			pip = pip->next;
		}
		pip->next = (t_pipe *)malloc(sizeof(t_pipe));
		pip = pip->next;
		pip->node = node;
		pip->next = NULL;
	}
	return (1);
}

int			creating_arrays(t_table *tbl)
{
	int		i;

	i = -1;
	tbl->q = (t_node**)malloc(sizeof(t_node*) * tbl->rooms + 1);
	tbl->q[tbl->rooms] = NULL;
	tbl->path = (t_node***)malloc(sizeof(t_node**) * tbl->rooms);
	while (++i < tbl->rooms)
		tbl->q[i] = NULL;
	i = -1;
	while (++i < tbl->rooms)
		tbl->path[i] = NULL;
	return (1);
}
