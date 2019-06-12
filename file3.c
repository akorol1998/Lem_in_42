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
	int		f;
	int		i;

	curr = tbl->nodes;
	
	while ((idx = set_levels(tbl)))
	{
		f = extract_path(tbl, idx);
		if (f == -1)
			printf("Erro, Not enough info, can't reach end\n");
		i = -1;
		while (tbl->q[++i])
			tbl->q[i] = NULL;
	}
		
	if (f)
		printf("good\n");
	else
		printf("bad\n");
	return (1);
}

void		making_path(t_table *tbl, int idx, int	j)
{
	t_node	*node;

	node = tbl->q[idx];
	tbl->path[j][idx - 1] = ft_strdup(node->name); // End node, don't mark as visited
	printf("\nnode %s [%d]\n", node->name, node->visited);
	idx--;
	while (ft_strcmp(node->name, tbl->start->name))
	{
		node = node->prev;
		node->visited = 1;
		printf("node %s [%d]\n", node->name, node->visited);
		tbl->path[j][idx - 1] = ft_strdup(node->name);
		idx--;
	}
	if (!ft_strcmp(node->name, tbl->start->name))
		node->visited = 0;
	printf("node %s [%d]\n", node->name, node->visited);
}

int			extract_path(t_table *tbl, int idx)
{
	int		i;
	int		j;

	i = -1;
	while (tbl->q[++i])
		;
	j = -1;
	while (tbl->path[++j])
		;
	if (!tbl->q[idx])
		return (-1);
	tbl->path[j] = (char**)malloc(sizeof(char*) * idx + 1);
	tbl->path[j][idx] = NULL;
	making_path(tbl, idx, j);
	printf("path number %d\n", j);
	printf("Extracting path\n");
	return (1);
}

void		add_to_queue(t_table *tbl, t_node *cur)
{
	t_pipe	*pip;
	int		i;
	int		flag;
	int		idx;

	idx = -1;
	pip = cur->branch;
	while (tbl->q[++idx])
		;
	pip = cur->branch;
	// t_pipe	*tub;
	// t_node	*node;

	// node = tbl->end;
	// tub = node->branch;
	// while (tub)
	// {
	// 	ft_putstr("yes ");
	// 	ft_putstr(node->name);
	// 	ft_putstr("\n");
	// 	tub = tub->next;
	// }
	while (pip)
	{
		i = -1;
		flag = 1;
		while (tbl->q[++i])
		{
			if (pip->node->visited && !ft_strcmp(tbl->q[i]->name, pip->node->name))
				flag = 0;
		}
		if (flag)
		{
			tbl->q[idx] = pip->node;
			pip->node->prev = cur;
			idx++;
		}
		ft_putstr("going from ");
		ft_putstr(pip->node->name);
		ft_putstr(" -> ");
		pip = pip->next;
		if (pip)
		{
			ft_putstr(pip->node->name);
			ft_putstr("\n");
		}
	}
}

int			set_levels(t_table *tbl)
{
	t_node	*cur;
	int		idx;
	int		flag;
	t_pipe	*pip;

	idx = 0;
	flag = 0;
	cur = tbl->nodes;
	pip = cur->branch;
	while (pip)
	{
		if (!pip->node->visited)
			flag = 1;
		pip = pip->next;
	}
	if (!flag)
		return (0);
	tbl->q[idx] = cur;
	while (cur && ft_strcmp(cur->name, tbl->end->name))
	{
		add_to_queue(tbl, cur);
		cur = tbl->q[++idx];
	}
	return (idx);
}
