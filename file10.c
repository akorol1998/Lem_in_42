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
	t_node	*save;

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
	save = node->vert[idx];
	delete_links(node, save);
}

void		delete_links(t_node *node, t_node *save)
{
	int		i;

	i = -1;
	while (node->vert && node->vert[++i])
	{
		if (ft_strcmp(save->name, node->vert[i]->name))
		{
			delete_from_vert(node, i);
			i--;
		}
	}
}

void		go_to_the_end(t_table *tbl, t_node *nd, int idx, int i)
{
	t_node	**verty;

	verty = nd->vert;
	while (verty && verty[0])
	{
		i++;
		nd = verty[0];
		tbl->path[idx][i] = nd;
		nd->visited = 1;
		printf("[%s]-", tbl->path[idx][i]->name);
		verty = nd->vert;
	}
	tbl->path[idx][++i] = NULL;
}

void		fill_paths(t_table *tbl)
{
	t_node	*nd;
	int		idx;
	int		i;
	int		j;

	j = -1;
	while (tbl->start->vert[++j])
	{
		idx = -1;
		while (tbl->path[++idx])
			;
		tbl->path[idx] = (t_node**)malloc(sizeof(t_node*) * tbl->rooms + 1);
		// i = -1;
		// while (++i < tbl->rooms + 1)
		// 	tbl->path[idx][i] = NULL;
		i = 0;
		nd = tbl->start->vert[j];
		tbl->path[idx][i] = nd;
		nd->visited = 1;
		printf("[%s]-", tbl->path[idx][i]->name);
		go_to_the_end(tbl, nd, idx, i);
		printf("\n");
	}
	tbl->end->visited = 0;
}