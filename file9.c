/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 13:21:09 by akorol            #+#    #+#             */
/*   Updated: 2019/06/16 13:21:20 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// Deleting input links to the node
void		delete_fork_func(t_node *pre, t_node *node)
{
	t_pipe	*pip;
	t_pipe	*prepip;

	while (pre->branch && !ft_strcmp(pre->branch->node->name, node->name))
	{
		pre->branch->node->out--;
		pre->branch = pre->branch->next;
		node->in--;
	}
	pip = pre->branch;
	while (pip)
	{
		if (!ft_strcmp(pip->node->name, node->name))
		{
			node->in--;
			pip->node->out--;
			prepip->next = pip->next;
		}
		prepip = pip;
		pip = pip->next;
	}
}

void		delete_output_forks(t_table *tbl)
{
	int		leng;

	leng = 0;
	while (tbl->q[leng])
		leng++;
	while (--leng >= 0)
	{
		if (tbl->q[leng]->out > 1 && ft_strcmp(tbl->q[leng]->name, tbl->start->name))
			remove_out_links(tbl, tbl->q[leng]);
	}
}

void		remove_out_links(t_table *tbl, t_node *node)
{
	t_pipe *pip;
	int		size;
	int		*arr;
	int		idx;

	size = 0;
	tbl = NULL;
	pip = node->branch;
	while (pip)
	{
		size++;
		pip = pip->next;
	}
	arr = (int*)malloc(sizeof(int) * size);
	pip = node->branch;
	idx = -1;
	while (pip)
	{
		++idx;
		short_way(arr, pip->node, idx);
		pip = pip->next;
	}
	delete_long_paths(arr, node, size);
	free(arr);
	
	// printf("node is %s [%d]\n", node->name, node->out); //think about it ;)
	// printf("size is %d\n", size);
}

void		refresh_outs(t_table *tbl)
{
	int		j;
	int		k;
	t_pipe	*br;


	j = -1;
	while (tbl->q[++j])
	{
		k = -1;
		br = tbl->q[j]->branch;
		while (br)
		{
			k++;
			br = br->next;
		}
		k++;
		tbl->q[j]->out = k;
	}
}

void		short_way(int *arr, t_node *node, int idx)
{
	int		count;
	t_pipe	*pip;

	count = 1;
	pip = node->branch;
	while (pip)
	{
		node = pip->node;// check weather it reaches the end
		pip = node->branch;
		count++;
	}
	arr[idx] = count;
	// printf("count %d\n", arr[idx]);
}