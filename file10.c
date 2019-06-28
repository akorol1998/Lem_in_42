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
	printf("Index [%d]\n", idx);
	save = node->vert[idx];
	// for(int k=0;node->vert[k];k++)
	// 	printf("counting %d\n", k);
	// printf("[%s]\n", save->name);
	// printf("Node [%s]\n", node->name);
	delete_links(node, save);
}

void		delete_links(t_node *node, t_node *save)
{
	// t_pipe	*pip;
	// t_pipe	*del;
	// t_pipe	*prepipe;
	// int		mydx;
		int		i;

	// mydx = 0;
	i = -1;
	printf("Pokemon\n");
	while (node->vert && node->vert[++i])
	{
		ft_putstr("still here\n");
		if (!save)
			ft_putstr("save Seg fault\n");
		if (ft_strcmp(save->name, node->vert[i]->name))
		{
			ft_putstr("Inside\n");
			delete_from_vert(node, i);
			i--;
		}
		// del = node->branch;
		// node->branch = node->branch->next;
		// free(del);
		// mydx++;
	}
	// pip = node->branch;
	// while (pip)
	// {
	// 	if (pip && mydx != idx)
	// 	{
	// 		del = prepipe->next;
	// 		prepipe->next = pip->next;
	// 		free(del);
	// 	}
	// 	prepipe = pip;
	// 	pip = pip->next;
	// 	mydx++;
	// }
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
		i = 0;
		nd = tbl->start->vert[j];
		tbl->path[idx][i] = nd;
		nd->visited = 1;
		printf("[%s]-", tbl->path[idx][i]->name);
		go_to_the_end(tbl, nd, idx, i);
		printf("\n");
	}
	tbl->end->visited = 0;
	printf("VISITED [%d]\n", tbl->start->visited);
}