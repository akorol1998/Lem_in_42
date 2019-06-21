/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:03:00 by akorol            #+#    #+#             */
/*   Updated: 2019/06/16 16:03:10 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_long_paths(int *arr, t_node *node, int size)
{
	int		a;
	int		i;
	int		idx;

	i = -1;
	a = 999999;
	idx = 999999;
	while (++i < size)
	{
		if (arr[i] < a)
		{
			a = arr[i];
			idx = i;
		}
	}
	delete_links(node, idx);
}

void		delete_links(t_node *node, int idx)
{
	t_pipe	*pip;
	t_pipe	*del;
	t_pipe	*prepipe;
	int		mydx;

	mydx = 0;
	while (node->branch && mydx != idx)
	{
		del = node->branch;
		node->branch = node->branch->next;
		free(del);
		mydx++;
	}
	pip = node->branch;
	while (pip)
	{
		if (pip && mydx != idx)
		{
			del = prepipe->next;
			prepipe->next = pip->next;
			free(del);
		}
		prepipe = pip;
		pip = pip->next;
		mydx++;
	}
}

void		go_to_the_end(t_table *tbl, t_node *nd, int idx, int i)
{
	t_pipe	*br;

	br = nd->branch;
	while (br)
	{
		i++;
		nd = br->node;
		// if (!nd->visited)
		tbl->path[idx][i] = nd;
		nd->visited = 1;
		printf("[%s]-", tbl->path[idx][i]->name);
		br = nd->branch;
	}
	tbl->path[idx][++i] = NULL;
}

void		fill_paths(t_table *tbl)
{
	t_pipe	*pip;
	t_node	*nd;
	int		idx;
	int		i;

	pip = tbl->start->branch;
	while (pip)
	{
		idx = -1;
		while (tbl->path[++idx])
			;
		tbl->path[idx] = (t_node**)malloc(sizeof(t_node*) * tbl->rooms + 1);
		tbl->path[idx][0] = tbl->start;
		printf("start-[%s]-", tbl->path[idx][0]->name);
		i = 1;
		nd = pip->node;
		tbl->path[idx][i] = nd;
		nd->visited = 1;
		printf("[%s]-", tbl->path[idx][i]->name);
		go_to_the_end(tbl, nd, idx, i);
		printf("\n");
		pip = pip->next;
	}
	tbl->end->visited = 0;
	printf("VISITED [%d]\n", tbl->start->visited);
}