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
	int		idx;

	curr = tbl->nodes;
	idx = set_levels(tbl);
	extract_path(tbl, idx);
	return (1);
}

void		making_path(t_table *tbl, int idx, int	j)
{
	t_node	*node;

	node = tbl->q[idx];
	tbl->path[j][idx - 1] = node->name;
	printf("index %d\n", idx);
	printf("room %s\n", tbl->path[j][idx - 1]);
	idx--;
	while (ft_strcmp(node->name, tbl->start->name))
	{
		node = node->prev;
		printf("index %d\n", idx);
		printf("node name %s\n", node->name);
		tbl->path[j][idx - 1] = node->name;
		idx--;
	}
	printf("start name %s\n", tbl->start->name);
}

void		extract_path(t_table *tbl, int idx)
{
	int		i;
	int		j;

	i = -1;
	while (tbl->q[++i])
		;
	j = -1;
	while (tbl->path[++j])
		;
	tbl->path[j] = (char**)malloc(sizeof(char*) * idx + 1);
	tbl->path[j][idx] = NULL;
	making_path(tbl, idx, j);
	printf("%d\n", i);
	printf("%d\n", j);
	printf("Extracting path");
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
	printf("iteration\n");					// Look here BITCH  check pip for being a NULL and file 'file'
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
			printf(" queue name %s\n", pip->node->name);
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
	printf("index is %d\n", idx);
	while (cur && ft_strcmp(cur->name, tbl->end->name))
	{
		add_to_queue(tbl, cur);
		cur = tbl->q[++idx];
		printf("cycle index is %d\n", idx);
		ft_putstr("Room = ");
		if (cur)
		{
			ft_putstr(cur->name);
			ft_putnbr(idx);
			ft_putstr("\n");
		}
	}
	ft_putstr("here is a node ");
	ft_putstr(cur->name);
	ft_putstr("\n");
	ft_putstr("here is end name ");
	ft_putstr(tbl->end->name);
	ft_putstr("\n");
	return (idx);
}
