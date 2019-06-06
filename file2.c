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
		return (0);
	while (node && ft_strcmp(node->name, data[0]))
	{
		printf("--------LINK1-------\n\n");
		node = node->link;
	}
	while (node2 && ft_strcmp(node2->name, data[1]))
	{
		printf("--------LINK2-------\n\n");
		node2 = node2->link;
	}
	if (node && node2 && connecting_nodes(node, node2))
		return (1);
	else
		return (0);				// FREE !!
	printf("\nwell hello\n");
	printf("%s-%s\n", data[0], data[1]);
}

// Very careful with linking nodes to each other, so that you didn't create infinite loop in the future

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
	tbl->prev = (char **)malloc(sizeof(char*) * tbl->rooms + 1);
	tbl->prev[tbl->rooms] = NULL;
	tbl->vis = (char **)malloc(sizeof(char*) * tbl->rooms + 1);
	tbl->vis[tbl->rooms] = NULL;
	tbl->unvis = (char **)malloc(sizeof(char*) * tbl->rooms + 1);
	tbl->unvis[tbl->rooms] = NULL;
	tbl->vert = (char **)malloc(sizeof(char*) * tbl->rooms + 1);
	tbl->vert[tbl->rooms] = NULL;
	tbl->start->weight = 0;
	fill_unvis(tbl);	
	return (1);
}

void		fill_unvis(t_table *tbl)
{
	t_node	*node;
	int		i;

	i = -1;
	node = tbl->nodes;
	while (node)
	{
		++i;
		tbl->unvis[i] = ft_strdup(node->name);
		tbl->vert[i] = ft_strdup(node->name);
		node->idx = i;
		node = node->link;
		printf("node %s\n", tbl->unvis[i]);
	}
	launch_algorithm(tbl);
}
